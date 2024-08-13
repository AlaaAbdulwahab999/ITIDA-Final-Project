#include "DataBaseHandler.h"
#include <QDebug>
#include <QRegularExpression>


// Constructor for the DataBaseHandler class
DataBaseHandler::DataBaseHandler(QObject *parent) : QObject(parent) {}

// Function to read a JSON array from a file
QJsonArray DataBaseHandler::readJsonArrayFromFile(const QString& fileName)
{
    QFile file(fileName);

    // Try to open the file in read-only mode
    if (!file.open(QIODevice::ReadOnly))
    {
        qWarning("Couldn't open file.");
        return QJsonArray();
    }

    // Read all the data from the file
    QByteArray saveData = file.readAll();

    // Create a QJsonDocument from the read data
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));

    // Return the JSON array from the document
    return loadDoc.array();
}


// Function to write a JSON array to a file
void DataBaseHandler::writeJsonArrayToFile(const QString& fileName, const QJsonArray& jsonArray) {
    QFile file(fileName);

    // Try to open the file in write-only mode
    if (!file.open(QIODevice::WriteOnly))
    {
        qWarning("Couldn't open file.");
        return;
    }

    // Create a QJsonDocument from the JSON array
    QJsonDocument saveDoc(jsonArray);

    // Write the JSON document to the file
    file.write(saveDoc.toJson());
}


// Function to get a user object by username
QJsonObject DataBaseHandler::getUserObject(const QString& username)
{
    // Read the JSON array from the login file
    QJsonArray jsonArray = readJsonArrayFromFile(loginFile);

    // Iterate through each value in the JSON array
    for (const QJsonValue& value : jsonArray)
    {
        QJsonObject obj = value.toObject();

        // Check if the username matches the requested username
        if (obj["username"].toString() == username)
        {
            return obj; // Return the user object if found
        }
    }

    return QJsonObject(); // Return an empty object if the user is not found
}

// Function to get a user object by account number
QJsonObject DataBaseHandler::getUserObjectByAccountNumber(const QString& accountNumber)
{
    // Read the JSON array from the login file
    QJsonArray jsonArray = readJsonArrayFromFile(loginFile);

    // Iterate through each value in the JSON array
    for (const QJsonValue& value : jsonArray) {
        QJsonObject obj = value.toObject();

        // Check if the account number matches the requested account number
        if (obj["accountNumber"].toString() == accountNumber)
        {
            return obj; // Return the user object if found
        }
    }

    return QJsonObject(); // Return an empty object if the user is not found
}

// Check if account number Exists or not
bool DataBaseHandler::accountNumberExists(const QString& accountNumber)
{
    QJsonObject userObject = getUserObjectByAccountNumber(accountNumber);
    return !userObject.isEmpty();
}

// Function to verify user login
bool DataBaseHandler::login(const QString& username, const QString& password)
{
    // Retrieve the user object by username
    QJsonObject user = getUserObject(username);

    // Check if the user object is not empty and the password matches
    if (!user.isEmpty() && user["password"].toString() == password)
    {
        return true; // Login is successful
    }

    return false; // Login failed
}

// Function to get the account number for a user
QString DataBaseHandler::getAccountNumber(const QString& username)
{
    // Retrieve the user object by username
    QJsonObject user = getUserObject(username);

    // Check if the user object is not empty
    if (!user.isEmpty())
    {
        return user["accountNumber"].toString(); // Return the account number
    }

    return QString(); // Return an empty string if the user is not found
}

// Function to get the balance for a user
int DataBaseHandler::getBalance(const QString& accountNumber)
{
    // Retrieve the user object by account number
    QJsonObject user = getUserObjectByAccountNumber(accountNumber);

    // Check if the user object is not empty
    if (!user.isEmpty()) {
        return user["balance"].toInt(); // Return the balance
    }

    return -1; // Return -1 if the user is not found
}

// Function to get the email for a user
QString DataBaseHandler::getUserEmail(const QString& username)
{
    // Retrieve the user object by username
    QJsonObject userObject = getUserObject(username);

    // Check if the user object is not empty
    if (!userObject.isEmpty())
    {
        return userObject["email"].toString(); // Return the email
    }

    return ""; // Return an empty string if the user is not found
}

// Function to get the username associated with a given account number
QString DataBaseHandler::getUserName(const QString &accountNumber)
{
    // Retrieve the user object by account number
    QJsonObject userObject = getUserObjectByAccountNumber(accountNumber);

    // Check if the user object is not empty
    if (!userObject.isEmpty())
    {
        return userObject["username"].toString(); // Return the username
    }

    return ""; // Return an empty string if the user is not found
}


// Function to perform a transaction on a user's account
bool DataBaseHandler::makeTransaction(const QString& accountNumber, int amount)
{
    // Read the list of users from the login file
    QJsonArray users = readJsonArrayFromFile(loginFile);

    // Iterate through each user object in the array
    for (QJsonValueRef value : users) {
        QJsonObject user = value.toObject();

        // Check if the account number matches the user’s account number
        if (user["accountNumber"].toString() == accountNumber) {
            // get and update the user's balance
            int balance = user["balance"].toInt();
            balance += amount;

            // Check if the new balance is negative (insufficient funds)
            if (balance < 0) return false;

            // Update the balance in the user object
            user["balance"] = balance;
            value = user; // Update the user object in the array

            // Log the transaction
            QJsonArray transactions = getTransactionArray(accountNumber);
            QJsonObject transaction;
            transaction["date"] = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"); //date and time
            transaction["amount"] = amount; // Set the transaction amount
            transaction["type"] = (amount > 0) ? "deposit" : "withdrawal"; // Set the transaction type
            transactions.append(transaction); // Add the new transaction to the array

            // Update the transactions in the transaction file
            QJsonArray transArray = readJsonArrayFromFile(transactionFile);
            for (QJsonValueRef transValue : transArray)
            {
                QJsonObject transObject = transValue.toObject();
                if (transObject["accountNumber"].toString() == accountNumber)
                {
                    transObject["transactions"] = transactions; // Update transactions for the account
                    transValue = transObject;
                    break;
                }
            }
            // Write the updated transactions and user data back to the files
            writeJsonArrayToFile(transactionFile, transArray);
            writeJsonArrayToFile(loginFile, users);

            return true; // Return true indicating the transaction was successful
        }
    }

    return false; // Return false if the account number was not found
}


// Retrieves the transaction array for a specific account number
QJsonArray DataBaseHandler::getTransactionArray(const QString& accountNumber)
{
    // Read the array of transactions from the transaction file
    QJsonArray jsonArray = readJsonArrayFromFile(transactionFile);

    // Iterate through each transaction object in the array
    for (const QJsonValue& value : jsonArray) {
        QJsonObject obj = value.toObject();

        // Check if the account number matches the one we're looking for
        if (obj["accountNumber"].toString() == accountNumber) {
            // Return the transactions associated with this account number
            return obj["transactions"].toArray();
        }
    }

    // Return an empty QJsonArray if no matching account number was found
    return QJsonArray();
}

QString DataBaseHandler::generateRandomAccountNumber()
{
    QString accountNumber;  // Declare a QString variable to store the generated account number

    // Loop until a unique account number is generated
    do
    {
        // Generate a random number between 100000 and 999999 (inclusive) and convert it to QString
        accountNumber = QString::number(QRandomGenerator::global()->bounded(100000, 999999));
    }
    // Continue looping as long as the generated account number already exists
    while (accountNumberExists(accountNumber));

    // Return the unique account number
    return accountNumber;
}


// Retrieves a specified number of recent transactions for a given account
QJsonObject DataBaseHandler::getTransactionHistory(const QString& accountNumber, int count)
{
    // Get the array of transactions for the specified account number
    QJsonArray transactions = getTransactionArray(accountNumber);
    QJsonArray historyArray;

    // Calculate the starting index for the transactions to get
    int startIndex = qMax(0, transactions.size() - count);

    // Append the requested number of transactions to the history array
    for (int i = startIndex; i < transactions.size(); ++i)
    {
        historyArray.append(transactions[i]);
    }

    // Create a QJsonObject to hold the account number and the transaction history
    QJsonObject history;
    history["accountNumber"] = accountNumber; // Store the account number
    history["transactions"] = historyArray;   // Store the array of transactions

    return history; // Return the QJsonObject containing the transaction history
}


// Transfers an amount from one account to another
bool DataBaseHandler::transferAmount(const QString& fromAN, const QString& toAN, int amount)
{
    // Deduct the amount from the source account
    if (makeTransaction(fromAN, -amount)) {
        // If successful, add the amount to the destination account
        return makeTransaction(toAN, amount);
    }
    // Return false if the deduction from the source account failed
    return false;
}


// Checks if the provided account number contains only digits
bool isAccountNumberValid(const QString& accountNumber)
{
    QRegularExpression regex("^[0-9]+$");  // Regular expression to match only digits
    QRegularExpressionMatch match = regex.match(accountNumber);
    return match.hasMatch();  // Returns true if the account number matches the regex
}

// Creates a new user and adds them to the users list
UserCreationStatus DataBaseHandler::createNewUser(QJsonObject userData)
{
    // Read the existing users from the login file
    QJsonArray users = readJsonArrayFromFile(loginFile);

    QString accountNumber = generateRandomAccountNumber();
    QString username = userData["username"].toString();

    // Check if the account number is valid (contains only digits)
    if (!isAccountNumberValid(accountNumber)) {
        return UserCreationStatus::InvalidAccountNumber;
    }

    // Check if a user with the same username already exists
    for (const QJsonValue& value : users) {
        QJsonObject user = value.toObject();
        if (user["username"].toString() == username) {
            return UserCreationStatus::UserAlreadyExists;
        }
    }

    // Add the account number to the user data
    userData["accountNumber"] = accountNumber;

    // Set default values for the new user
    userData["balance"] = 0;  // Initial balance
    userData["role"] = "user"; // Default role for new users

    // Add the new user to the users array
    users.append(userData);

    // Write the updated users array back to the file
    writeJsonArrayToFile(loginFile, users);

    // Read the existing transactions from the transactions file
    QJsonArray transactions = readJsonArrayFromFile(transactionFile);

    // Create a new transaction entry for the new user
    QJsonObject newTransactionEntry;
    newTransactionEntry["accountNumber"] = accountNumber;
    newTransactionEntry["transactions"] = QJsonArray();

    // Add the new transaction entry to the transactions array
    transactions.append(newTransactionEntry);

    // Write the updated transactions array back to the file
    writeJsonArrayToFile(transactionFile, transactions);

    return UserCreationStatus::Success; // Indicate successful user creation
}



// Updates user information for a given account number with the new data provided
UserUpdateStatus DataBaseHandler::updateUser(const QString& accountNumber, const QJsonObject& newData)
{
    // Read the existing users from the login file
    QJsonArray users = readJsonArrayFromFile(loginFile);

    // Check if the new username already exists in the database
    QString newUsername = newData["username"].toString();
    if (!newUsername.isEmpty()) {
        for (const QJsonValue& value : users)
        {
            QJsonObject user = value.toObject();
            // Check if the new username is already taken by a different account
            if (user["username"].toString() == newUsername &&
                user["accountNumber"].toString() != accountNumber)
            {
                return UserUpdateStatus::UsernameAlreadyExists; // Username conflict
            }
        }
    }

    // Find the user with the specified account number and update their data
    for (QJsonValueRef value : users) {
        QJsonObject user = value.toObject();
        if (user["accountNumber"].toString() == accountNumber)
        {
            // Update the user data with the new values
            for (const QString& key : newData.keys())
            {
                user[key] = newData[key];
            }
            value = user; // Replace old user data with updated data
            writeJsonArrayToFile(loginFile, users); // Write the updated users list back to the file
            return UserUpdateStatus::SuccessUpdate; // Indicate successful update
        }
    }

    // Return status if the account number was not found
    return UserUpdateStatus::AccountNotFound;
}

// Deletes a user with a specific account number from the database
bool DataBaseHandler::deleteUser(const QString& accountNumber)
{
    // Read the existing users from the login file
    QJsonArray users = readJsonArrayFromFile(loginFile);
    bool userDeleted = false;

    // Iterate through the users to find and remove the user with the specified account number
    for (QJsonArray::Iterator it = users.begin(); it != users.end(); ++it)
    {
        if ((*it).toObject()["accountNumber"].toString() == accountNumber)
        {
            users.erase(it); // Remove the user from the array
            userDeleted = true; // Indicate that a user was deleted
            break; // Exit the loop after deleting the user
        }
    }

    // If a user was deleted, write the updated users list back to the file
    if (userDeleted) {
        writeJsonArrayToFile(loginFile, users);

        // Read the existing transactions from the transactions file
        QJsonArray transactions = readJsonArrayFromFile(transactionFile);

        // Iterate through the transactions to find and remove the entry with the specified account number
        for (QJsonArray::Iterator it = transactions.begin(); it != transactions.end(); ++it)
        {
            if ((*it).toObject()["accountNumber"].toString() == accountNumber)
            {
                transactions.erase(it); // Remove the transaction entry from the array
                break; // Exit the loop after deleting the transaction entry
            }
        }

        // Write the updated transactions array back to the file
        writeJsonArrayToFile(transactionFile, transactions);
    }

    // Return whether the user was deleted
    return userDeleted;
}



// Retrieves the entire bank database as a QVector of QJsonObject
QVector<QJsonObject> DataBaseHandler::viewBankDatabase()
{
    // Read the list of users from the login file
    QJsonArray users = readJsonArrayFromFile(loginFile);
    QVector<QJsonObject> userVector;

    // Convert each QJsonValue in the QJsonArray to QJsonObject and append to the QVector
    for (const QJsonValue& value : users) {
        userVector.append(value.toObject());
    }

    // Return the QVector containing all user objects
    return userVector;
}

// Retrieves the role of a user based on their username
QString DataBaseHandler::getUserRole(const QString& username)
{
    // Get the user object for the specified username
    QJsonObject user = getUserObject(username);
    if (!user.isEmpty()) {
        // Return the role of the user
        return user["role"].toString();
    }
    // Return an empty QString if the user is not found
    return QString();
}

// Withdraws a specified amount from the account associated with the given account number
bool DataBaseHandler::withdrawAmount(const QString& accountNumber, double amount)
{
    // Check if the amount to withdraw is positive
    if (amount <= 0) {
        qWarning("Withdrawal amount must be positive.");
        return false;
    }

    // Check if the account has sufficient balance for the withdrawal
    if (getBalance(accountNumber) < amount) {
        qWarning("Insufficient balance for withdrawal.");
        return false;
    }

    // Process the withdrawal transaction
    return makeTransaction(accountNumber, -amount);
}


// Deposits a specified amount into the account associated with the given account number
bool DataBaseHandler::depositAmount(const QString& accountNumber, double amount)
{
    // Check if the amount to deposit is positive
    if (amount <= 0) {
        qWarning("Deposit amount must be positive.");
        return false;
    }

    // Process the deposit transaction
    return makeTransaction(accountNumber, amount);
}

