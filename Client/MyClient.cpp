#include "MyClient.h"
#include <QCryptographicHash>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QIODevice>
#include <QTcpSocket>
#include <QString>

// Constructor for the MyClient class
MyClient::MyClient(QObject *parent)
    : QObject{parent}
{
    // Connect signals to their respective slots
    connect(&socket, &QTcpSocket::connected, this, &MyClient::onConnection);
    connect(&socket, &QTcpSocket::disconnected, this, &MyClient::onDisconnected);
    connect(&socket, &QTcpSocket::errorOccurred, this, &MyClient::onErrorOccurred);
    connect(&socket, &QTcpSocket::stateChanged, this, &MyClient::onStateChanged);
    connect(&socket, &QTcpSocket::readyRead, this, &MyClient::onReadyRead);
}

// function to connect to a device (server) using IP address and port number
void MyClient::ConnectToDevice(const QString &ip, qint32 port)
{
    // Check if the socket is already open
    if (socket.isOpen())
    {
        // If the same IP and port, do nothing
        if ((this->ip == ip) && (this->port == port))
        {
            return;
        }
        else
        {
            // If different IP or port, close the current connection and connect to the new address
            socket.close();
            this->port = port;
            this->ip = ip;
            socket.connectToHost(this->ip, this->port);
        }
    }
    else
    {
        // If the socket is not open, set the IP and port and connect to the host
        this->port = port;
        this->ip = ip;
        socket.connectToHost(this->ip, this->port);
    }
}

// function to disconnect from the device (server)
void MyClient::Disconnect()
{
    if (socket.isOpen())
    {
        socket.close();
    }
}

// Slot called when the connection to the server is established
void MyClient::onConnection()
{
    emit Connection(); // Emit the Connection signal
}

// Slot called when the connection to the server is disconnected
void MyClient::onDisconnected()
{
    emit Disconnected(); // Emit the Disconnected signal
}

// Slot called when an error occurs with the socket
void MyClient::onErrorOccurred(QAbstractSocket::SocketError socketError)
{
    emit ErrorOccurred(socketError); // Emit the ErrorOccurred signal with the error code
}

// Slot called when the state of the socket changes
void MyClient::onStateChanged(QAbstractSocket::SocketState socketState)
{
    // If the socket state is UnconnectedState, close the socket
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        socket.close();
    }
    emit StateChanged(socketState); // Emit the StateChanged signal with the new state
}

// Slot called when data is available to read from the socket
void MyClient::onReadyRead()
{
    QByteArray byteArray = socket.readAll(); // Read all available data from the socket
    QString str = QString(byteArray); // Convert the data to a QString
    qint32 jsonSize = str.split("/")[0].split(":")[1].toInt(); // Extract the size of the JSON data
    QString data = str.right(jsonSize); // Extract the actual JSON data

    QJsonDocument jsonDoc = QJsonDocument::fromJson(data.toUtf8()); // Parse the JSON data
    QJsonObject jsonObject = jsonDoc.object(); // Convert the JSON document to a JSON object
    QString encryptedData = jsonObject["File_data"].toString(); // Get the encrypted data from the JSON object
    QString requestType = jsonObject["request_type"].toString(); // Get the request type from the JSON object
    Role = jsonObject["Role"].toString(); // Get the role from the JSON object
    Email = jsonObject["Email"].toString(); // Get the email from the JSON object

    QString encryptionKey = "Alaa"; // Define the encryption key

    QString decryptedMessage = decryptMessage(encryptedData, encryptionKey); // Decrypt the message
    emit ReadyRead(requestType, decryptedMessage); // Emit the ReadyRead signal with the request type and decrypted message
}
//function to send request for the server
void MyClient::sendRequest(const QString &dataToSend)
{
    QByteArray dataToEncrypt = dataToSend.toUtf8();

    // Create JSON object for the request
    QJsonObject jsonObject;
    jsonObject["File_type"] = "Request";
    jsonObject["File_size"] = dataToEncrypt.size();  // Size of the data to be sent
    jsonObject["File_data"] = dataToSend;
    // Extract request type from JSON
    jsonObject["request_type"] = QJsonDocument::fromJson(dataToEncrypt).object().value("request_type").toString();
    jsonObject["Role"] = "";
    jsonObject["Email"] = "";

    // Create JSON document from the object
    QJsonDocument requestDoc(jsonObject);
    QByteArray byteArray = requestDoc.toJson(QJsonDocument::Compact);

    // Calculate the signature (hash) of the data
    QByteArray hashed = QCryptographicHash::hash("March", QCryptographicHash::Sha256);
    QByteArray signature = hashed.toHex() + "?";

    // Construct the header with the size of the JSON data
    QString header = QString("jsonSize:%1/").arg(byteArray.size());

    // Concatenate the signature, header, and JSON data
    byteArray.prepend(header.toUtf8());
    // Append the signature before the header and JSON data
    byteArray.prepend(signature);
    // Encrypt all data
    QString encryptedMessage = encryptMessage(byteArray, "Alaa");

    // Send the data through the socket
    socket.write(encryptedMessage.toUtf8());
    socket.flush();  // Ensure that the data is sent
}

// Function to encrypt a message using a key
QString MyClient::encryptMessage(const QString &message, const QString &key)
{
    // Convert the key to a UTF-8 encoded byte array
    QByteArray keyData = key.toUtf8();

    // Convert the message to a UTF-8 encoded byte array
    QByteArray messageData = message.toUtf8();

    // Hash the key using SHA-256 to produce a 32-byte hashed key
    QByteArray hashedKey = QCryptographicHash::hash(keyData, QCryptographicHash::Sha256);

    // Initialize the encryptedData array with the same content as messageData
    QByteArray encryptedData = messageData;

    // Encrypt the message by XOR-ing each byte with the corresponding byte in the hashed key
    // The % operator ensures that we loop over the hashed key if it is shorter than the message
    for (int i = 0; i < messageData.size(); ++i)
    {
        encryptedData[i] = encryptedData[i] ^ hashedKey[i % hashedKey.size()];
    }
    // Convert the encrypted byte array to a Base64-encoded string and return it
    return encryptedData.toBase64();
}

// Function to decrypt a message using a key
QString MyClient::decryptMessage(const QString &encryptedMessage, const QString &key)
{
    // Convert the key to a UTF-8 encoded byte array
    QByteArray keyData = key.toUtf8();
    // Decode the Base64-encoded encrypted message to get the original byte array
    QByteArray encryptedData = QByteArray::fromBase64(encryptedMessage.toUtf8());
    // Hash the key using SHA-256 to produce a 32-byte hashed key
    QByteArray hashedKey = QCryptographicHash::hash(keyData, QCryptographicHash::Sha256);
    // Initialize the decryptedData array with the same content as encryptedData
    QByteArray decryptedData = encryptedData;

    // Decrypt the message by XOR-ing each byte with the corresponding byte in the hashed key
    // The % operator ensures that we loop over the hashed key if it is shorter than the message
    for (int i = 0; i < encryptedData.size(); ++i)
    {
        decryptedData[i] = decryptedData[i] ^ hashedKey[i % hashedKey.size()];
    }
    // Convert the decrypted byte array to a QString and return it
    return QString(decryptedData);
}
