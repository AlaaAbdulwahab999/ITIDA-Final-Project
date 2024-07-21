#include "MyServerHandler.h"

// Initialize the thread with the provided ID and parent
// Create a new DataBaseHandler and assign it to dbHandler
// Initialize userHandler and adminHandler as null
MyServerHandler::MyServerHandler(int ID, QObject *parent)
    : QThread(parent), id(ID), socket(nullptr), dbHandler(new DataBaseHandler(this)),
    userHandler(nullptr),
    adminHandler(nullptr)
{
}

// Initializes the UserHandler and AdminHandler instances and configures signal-slot connections.
void MyServerHandler::initializeHandlers()
{
    // Create instances of UserHandler and AdminHandler
    userHandler = new UserHandler(dbHandler, username, Email, nullptr);
    adminHandler = new AdminHandler(dbHandler, username, nullptr);

    // Move userHandler and adminHandler to this thread to ensure thread safety
    userHandler->moveToThread(this);
    adminHandler->moveToThread(this);

    // Connect signals from UserHandler to slots in MyServerHandler
    connect(userHandler, &UserHandler::sendMessage, this, &MyServerHandler::SendMessage, Qt::DirectConnection);
    connect(userHandler, &UserHandler::logRequest, this, &MyServerHandler::logRequest, Qt::DirectConnection);
    connect(userHandler, &UserHandler::sendEmail, this, &MyServerHandler::sendEmail, Qt::DirectConnection);

    // Connect signals from AdminHandler to slots in MyServerHandler
    connect(adminHandler, &AdminHandler::sendMessage, this, &MyServerHandler::SendMessage, Qt::DirectConnection);
}

// The entry point for the QThread execution. This function is executed when the thread starts.
// It initializes the socket for communication with the client and sets up necessary signal-slot connections.
// It also sends a welcome message to the client and starts the event loop to handle client interactions.
void MyServerHandler::run()
{
    qDebug() << "Client " << id << " is running on thread => " << QThread::currentThreadId() << Qt::endl;
    // Create a new QTcpSocket instance for handling client communication
    socket = new QTcpSocket;

    // Set the socket descriptor to the ID provided for this connection
    socket->setSocketDescriptor(id);

    // Use Qt::DirectConnection to ensure the slot is called immediately when the signal is emitted
    connect(socket, &QTcpSocket::readyRead, this, &MyServerHandler::onReadyRead, Qt::DirectConnection);
    connect(socket, &QTcpSocket::disconnected, this, &MyServerHandler::onDisconnected, Qt::DirectConnection);

    // Send a welcome message to the client indicating that they need to log in
    SendMessage("Welcome to the Bank Server. Please Login.", "Welcome");

    // Enter the event loop to process incoming signals and slots
    exec();
}

// Logs a message to a file with a timestamp. This function appends the message to a log file,
//including the current date and time.
void MyServerHandler::logRequest(const QString &message)
{
    QFile file(Log_file);
    // Attempt to open the log file in append and text mode
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        // Create a QTextStream object to write text to the file
        QTextStream out(&file);

        // Get the current date and time formatted as "yyyy-MM-dd HH:mm:ss"
        QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

        // Write the timestamp and the provided message to the log file
        out << "[" << timestamp << "] " << message << "\n";
        file.close();
    } else
    {
        // If the file could not be opened, log a warning message to the debug output
        qWarning() << "Failed to open log file for writing.";
    }
}

//This function used to encrypt the data
QByteArray MyServerHandler::encryptMessage(const QString &message, const QString &key)
{
    // Convert the key and message to QByteArray for processing
    QByteArray keyData = key.toUtf8();
    QByteArray messageData = message.toUtf8();

    // Generate a SHA-256 hash of the key to use for encryption
    QByteArray hashedKey = QCryptographicHash::hash(keyData, QCryptographicHash::Sha256);

    // Initialize encryptedData with the original messageData
    QByteArray encryptedData = messageData;

    // XOR each byte of the message with the corresponding byte of the hashed key
    for (int i = 0; i < messageData.size(); ++i) {
        encryptedData[i] = encryptedData[i] ^ hashedKey[i % hashedKey.size()];
    }

    // Encode the encrypted data in Base64 and return
    return encryptedData.toBase64();
}

//This function used to Decrypt the data
QString MyServerHandler::decryptMessage(const QString &encryptedMessage, const QString &key)
{
    // Convert the key to QByteArray
    QByteArray keyData = key.toUtf8();

    // Decode the Base64-encoded encrypted message
    QByteArray encryptedData = QByteArray::fromBase64(encryptedMessage.toUtf8());

    // Generate a SHA-256 hash of the key to use for decryption
    QByteArray hashedKey = QCryptographicHash::hash(keyData, QCryptographicHash::Sha256);

    // Initialize decryptedData with the encryptedData
    QByteArray decryptedData = encryptedData;

    // XOR each byte of the encrypted data with the corresponding byte of the hashed key
    for (int i = 0; i < encryptedData.size(); ++i)
    {
        decryptedData[i] = decryptedData[i] ^ hashedKey[i % hashedKey.size()];
    }

    // Convert decrypted data back to QString and return
    return QString(decryptedData);
}

// This function used to send the responce message to the client
void MyServerHandler::SendMessage(const QString &message, const QString &requestType) {
    // Check if the socket is open before sending data
    if (socket->isOpen())
    {
        // Define an encryption key (use a secure key in a real application)
        QString encryptionKey = "Alaa";

        // Encrypt the message using the specified key
        QByteArray encryptedMessage = encryptMessage(message, encryptionKey);

        // Create a QJsonObject to hold the message and metadata
        QJsonObject jsonObject;
        jsonObject["File_type"] = "Message";  // Type of the file data
        jsonObject["File_size"] = encryptedMessage.size();  // Size of the encrypted message
        jsonObject["File_data"] = QString(encryptedMessage);  // Encrypted message data
        jsonObject["request_type"] = requestType;  // Type of the request ( login, getaccountnumber and so on)
        jsonObject["Role"] = role;  // Role of the user (admin, user)

        // Convert the QJsonObject to a QJsonDocument and then to a QByteArray
        QJsonDocument jsonDoc(jsonObject);
        QByteArray byteArray = jsonDoc.toJson(QJsonDocument::Compact);

        // Add a header with the size of the JSON data
        QString header = QString("jsonSize:%1/").arg(byteArray.size());
        byteArray.prepend(header.toUtf8());

        // Write the byte array to the socket and flush it to ensure data is sent
        socket->write(byteArray);
        socket->flush();
    }
}


//this function used to send the email to the user
void MyServerHandler::sendEmail(const QString &to, const QString &subject, const QString &body)
{
    QProcess process;


    // Prepare arguments
    QStringList arguments;
    arguments << to << subject << body;

    // Start the batch script with arguments
    qDebug() << "Starting batch script with arguments:" << arguments;
    process.start(batchFilePath, arguments);
    if (!process.waitForFinished())
    {
        qDebug() << "Failed to run batch script:" << process.errorString();
        return;
    }

    // Read and display the output or error
    QString output = process.readAllStandardOutput();
    QString error = process.readAllStandardError();
    if (!error.isEmpty())
    {
        qDebug() << "Error sending email:" << error;
    }
    else
    {
        qDebug() << "The email was sent successfully" <<Qt::endl;
    }
}

//this function used to recive the request from the client and parse the data
void MyServerHandler::onReadyRead()
{
    //read all coming data
    QByteArray byteArray = socket->readAll();
    //decrypt the data by using key ->"Alaa"
    QString str = decryptMessage(byteArray,"Alaa");

    //Extract the signature and compare it to the one has been sent
    QByteArray hashed = QCryptographicHash::hash("March", QCryptographicHash::Sha256);
    QByteArray signature = hashed.toHex();

    //Check the signature
    if(str.contains(signature))
    {
        // Extract JSON size and data from the received string
        qint32 jsonSize = str.split("/")[0].split(":")[1].toInt();
        QString data = str.right(jsonSize);

        // Parse the JSON data
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8());
        QJsonObject jsonObject = jsonDoc.object();
        qint32 dataSize = jsonObject["File_size"].toInt();
        QString encryptedData = jsonObject["File_data"].toString();
        // Decrypt the received message
        QString realData = encryptedData;

        // Check if the decrypted data size matches the expected size
        if (dataSize == realData.size())
        {
            QJsonDocument requestDoc = QJsonDocument::fromJson(realData.toUtf8());
            QJsonObject requestObject = requestDoc.object();
            QString requestTypeFromData = requestObject["request_type"].toString();  // Extract request type from the actual data
            QJsonObject requestData = requestObject["data"].toObject();

            if (requestTypeFromData == "Login")
            {
                username = requestData["username"].toString();  // Set the username for Login request
            }

            qDebug() << "Received request from client =>" << id << "=> Request Type:" << requestTypeFromData;
            qDebug() << "Client Username:" << username;
            role = dbHandler->getUserRole(username);
            Email= dbHandler->getUserEmail(username);
            QString logMessage = QString("Received request from client => %1 => Request Type: %2, Client Username: %3")
                                     .arg(id).arg(requestTypeFromData).arg(username);
            logRequest(logMessage);

            // Call handleOperation with the request type from the actual data
            handleOperation(requestTypeFromData, requestData);
        } else
        {
            QString errorMessage = "Data size mismatch. Expected: " + QString::number(dataSize) + ", Actual: " + QString::number(realData.size());
            SendMessage(errorMessage, "Error");
            qDebug() << errorMessage;
        }
    }
    else
    {
        qDebug()<<"error signature" <<Qt::endl;
    }
}
//this function used to handle all opearations
void MyServerHandler::handleOperation(const QString &requestType, QJsonObject requestData) {
    if (requestType == "Login")
    {
        handleLogin(requestData);
    }
    else if (requestType == "CreateNewUser")
    {
        adminHandler-> handleCreateNewUser(requestData);
    }
    else if (requestType == "DeleteUser")
    {
        QString accountNumber = requestData["account_number"].toString();
        adminHandler->  handleDeleteUser(accountNumber);
    }
    else if (requestType == "UpdateUserData")
    {
        adminHandler->  handleUserUpdate(requestData);
    }
    else if (requestType == "TransferAmount")
    {
        userHandler->handleTransferAmount(requestData);
    }
    else if (requestType == "GetBalanceAdmin")
    {
        QString accountNumber = requestData["account_number"].toString();
        adminHandler-> handleGetBalanceAdmin(accountNumber);
    }
    else if (requestType == "GetTransactionHistoryAdmin")
    {
        adminHandler->handleGetTransactionHistoryAdmin(requestData);
    }
    else if (requestType == "GetBalance")
    {
        QString accountNumber = requestData["account_number"].toString();
        userHandler-> handleGetBalance(accountNumber);
    }
    else if (requestType == "GetHistory")
    {
        userHandler->handleGetTransactionHistory(requestData);
    }
    else if (requestType == "ViewBankDataBase")
    {
        adminHandler-> handleViewBankDatabase();
    }
    else if (requestType == "GetAccountNumber")
    {
        username = requestData["username"].toString();
        userHandler->handleGetAccountNumber(username);
    }
    else if (requestType == "GetAccountNumberAdmin")
    {
        adminHandler-> handleGetAccountNumberAdmin(requestData);
    }
    else if (requestType == "Withdraw")
    {
        userHandler-> handleWithdraw(requestData);
    }
    else if (requestType == "Exit")
    {
        handleLogout();
    }else if (requestType == "Deposit")
    {
        userHandler-> handleDeposit(requestData);
    }
    else if (requestType == "Help")
    {
        handleHelperFunction();
    }
    else
    {
        SendMessage("Invalid request type: " + requestType,"");
    }
}

//function to handle login
void MyServerHandler::handleLogin(const QJsonObject &requestData)
{
    // Extract username and password from the request data
    QString username = requestData["username"].toString();
    QString password = requestData["password"].toString();

    // Attempt to log in using the provided username and password
    bool success = dbHandler->login(username, password);
    if (success) {
        // Login successful
        this->username = username;  // Store the username in the class member
        this->Email = dbHandler->getUserEmail(username);  // Retrieve and store the user's email
        role = dbHandler->getUserRole(username);  // Retrieve and store the user's role

        // Initialize handlers after a successful login to handle further operations
        initializeHandlers();

        // Send a success message to the client based on their role
        if (role == "admin") {
            SendMessage("Login successful! Welcome " + username, "Login");
        } else {
            SendMessage("Login successful! Welcome Dear " + username, "Login");
        }
        // Log the successful login event for debugging purposes
        qDebug() << "Client Username:" << username << "Login successful";
    } else
    {
        // Login failed
        SendMessage("Invalid username or password.", "Login");

        // Log the failed login attempt for debugging purposes
        qDebug() << "Client Username:" << username << "Login Failed";
    }
}
//function to Handle logout
void MyServerHandler::handleLogout()
{
    // Clear the stored username and role to indicate that the user has logged out
    this->username.clear();
    this->role.clear();

    // Send a logout confirmation message to the client
    SendMessage("Logout successful. Goodbye!", "Exit");
}

//Helper function
void MyServerHandler::handleHelperFunction()
{
    SendMessage("Enter 'Start' to Start The System\n"
                "Enter 'Connect' to Connect To the Server\n"
                "Enter 'Login' to Login to The System\n"
                "Enter 'Exit' to  Exit The System\n"
                "Enter 'LogOut' to Logout from The System\n"
                "Enter 'Get Account Number' to Get account Number\n"
                "Enter 'Get Balance' to Get Balance\n"
                "Enter 'View Data Base' to Get All Bank DataBase\n"
                "Enter 'View Transction History' to Get Transction History To account'\n"
                "Enter 'Add User' to Add New User\n"
                "Enter 'Update User' to Update The user data\n"
                "Enter 'withdraw' to Take Money from Your Account\n"
                "Enter 'Deposit' to put Money in Your Account\n"
                "Enter 'Transfer' to to Transefer Money From Your Account To Another Account\n"
                ,"Help");

}

void MyServerHandler::onDisconnected()
{
    if (socket->isOpen())
    {
        socket->close();
    }
    qDebug() << "Client " << id << " has disconnected." << Qt::endl;
}
