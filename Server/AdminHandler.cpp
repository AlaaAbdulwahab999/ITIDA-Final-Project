#include "AdminHandler.h"


// Constructor for the AdminHandler class
// Initializes the dbHandler and username members

AdminHandler::AdminHandler(DataBaseHandler *dbHandler, const QString &username, QObject *parent)
    : QObject(parent), dbHandler(dbHandler), username(username) {}

// Function to handle the GetAccountNumberAdmin request
void AdminHandler::handleGetAccountNumberAdmin(const QJsonObject &requestData)
{
    // Extract the username from the request data
    QString _username = requestData["_username"].toString();
    QString accountNum;

    // Get the account number from the database handler
    accountNum = dbHandler->getAccountNumber(_username);

    // Check if the account number is not empty
    if (!accountNum.isEmpty())
    {
        // Emit a success message with the account number
        emit sendMessage("Account number for user " + _username + ": " + accountNum, "GetAccountNumberAdmin");
    }
    else
    {
        // Emit an error message indicating no account was found
        emit sendMessage("No account found for user: " + _username, "GetAccountNumberAdmin");
    }
}

// Function to handle the UserUpdate request
void AdminHandler::handleUserUpdate(const QJsonObject &requestData)
{
    // Check if the request data contains an account number
    if (requestData.contains("accountNumber"))
    {
        // Extract the account number from the request data
        QString accountNumber = requestData["accountNumber"].toString();
        QJsonObject newData = requestData;
        QString message;
        // Update the user information in the database
        UserUpdateStatus status = dbHandler->updateUser(accountNumber, newData);

        // Handle the different update statuses
        switch (status)
        {
        case UserUpdateStatus::SuccessUpdate:
            // Emit a success message if the update was successful
            message= "User updated successfully!";
            break;

        case UserUpdateStatus::UsernameAlreadyExists:
            // Emit an error message if the username already exists
            message = "Failed to update user: Username already exists.";
            break;

        case UserUpdateStatus::AccountNotFound:
            // Emit an error message if the account number was not found
            message = "Failed to update user: Account number not found.";
            break;
        }
        emit sendMessage(message ,"UpdateUserData");
    }
    else
    {
        // Log a warning and emit an error message if no account number was provided
        qWarning() << "No account number provided in request.";
        emit sendMessage("Failed to update user: no account number provided.", "UpdateUserData");
    }
}



// Function to handle the DeleteUser request
void AdminHandler::handleDeleteUser(const QString &accountNumber)
{
    // Attempt to delete the user from the database
    bool success = dbHandler->deleteUser(accountNumber);

    // Check if the deletion was successful
    if (success)
    {
        // Emit a success message if the user was deleted
        emit sendMessage("User deleted successfully!", "DeleteUser");
    }
    else
    {
        // Emit an error message if the deletion failed
        emit sendMessage("Failed to delete user.", "DeleteUser");
    }
}


// Function to handle the CreateNewUser request
void AdminHandler::handleCreateNewUser(QJsonObject &requestData)
{
    // Attempt to create a new user in the database
    UserCreationStatus status = dbHandler->createNewUser(requestData);
    QString message;

    // Handle the different creation statuses
    switch (status) {
    case UserCreationStatus::Success:
        // Set the success message if the user was created successfully
        message = "User created successfully!";
        break;
    case UserCreationStatus::InvalidAccountNumber:
        // Set an error message if the account number was invalid
        message = "Failed to create user: Invalid account number. Please enter a numeric account number.";
        break;
    case UserCreationStatus::UserAlreadyExists:
        // Set an error message if the account number or username already exists
        message = "Failed to create user: Account number or username already exists.";
        break;
    }

    // Emit message based on the status
    emit sendMessage(message, "CreateNewUser");
}

// Function to handle the GetBalanceAdmin request
void AdminHandler::handleGetBalanceAdmin(const QString &accountNumber)
{
    // Get the role of the current user
    QString userRole = dbHandler->getUserRole(this->username);

    // Check if the user is an admin
    if (userRole == "admin")
    {
        // Admin can get the balance for any account number
        int balance = dbHandler->getBalance(accountNumber);

        // Emit the balance information
        emit sendMessage("Balance for account " + accountNumber + ": " + QString::number(balance), "GetBalanceAdmin");
    }
    else
    {
        // If the user is not an admin, do nothing
        return;
    }
}

// Function to handle the GetTransactionHistoryAdmin request
void AdminHandler::handleGetTransactionHistoryAdmin(const QJsonObject &requestData)
{
    // Extract the account number and count from the request data
    QString accountNumber = requestData["account_number"].toString();
    int count = requestData["count"].toInt();
    // Get the role of the current user
    QString userRole = dbHandler->getUserRole(this->username);
    // Check if the user is an admin
    if (userRole == "admin")
    {
        // Check if the account number exists
        bool accountExists = dbHandler->accountNumberExists(accountNumber);

        if (accountExists)
        {
            // Admin can get the transaction history for any account number
            QJsonObject history = dbHandler->getTransactionHistory(accountNumber, count);
            QJsonDocument doc(history);
            // Convert the history object to a JSON string
            QString jsonString = doc.toJson(QJsonDocument::Indented);
            // Emit the transaction history information
            emit sendMessage(jsonString, "GetTransactionHistoryAdmin");
        }
        else
        {
            emit sendMessage("Account number does not exist", "GetTransactionHistoryAdmin");
        }
    }
    else
    {
        // If the user is not an admin
        return;
    }
}


// Function to handle the ViewBankDatabase request
void AdminHandler::handleViewBankDatabase()
{
    // Get the bank database from the database handler
    QVector<QJsonObject> database = dbHandler->viewBankDatabase();

    // Convert the database vector to a JSON array
    QJsonArray jsonArray = QJsonArray::fromVariantList(QVariant::fromValue(database).toList());
    QJsonDocument doc(jsonArray);

    // Emit the bank database as a JSON string
    emit sendMessage(QString(doc.toJson(QJsonDocument::Indented)), "ViewBankDataBase");
}


