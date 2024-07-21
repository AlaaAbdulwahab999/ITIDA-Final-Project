#include "Admin.h"
#include "MyClient.h"

// Constructor for Admin class
Admin::Admin(MyClient& client, QObject *parent)
    : QObject(parent), client(client) {}

// function to get the account number for a user given a username
void Admin::getAccountNumberAdmin(const QString& username)
{
    // Create JSON request object
    QJsonObject requestObject;
    requestObject["request_type"] = "GetAccountNumberAdmin";

    // Add username to data object
    QJsonObject dataObject;
    dataObject["_username"] = username;
    requestObject["data"] = dataObject;

    // Convert request object to JSON string
    QJsonDocument requestDoc(requestObject);
    QString requestString = requestDoc.toJson(QJsonDocument::Compact);

    // Send request to the server
    client.sendRequest(requestString);
}

// function to get the balance for auser given an account number
void Admin::getBalanceAdmin(const QString& Acc_Number)
{
    // Create JSON request object
    QJsonObject requestObject;
    requestObject["request_type"] = "GetBalanceAdmin";

    // Add account number to data object
    QJsonObject dataObject;
    dataObject["account_number"] = Acc_Number;
    requestObject["data"] = dataObject;

    // Convert request object to JSON string
    QJsonDocument requestDoc(requestObject);
    QString requestString = requestDoc.toJson(QJsonDocument::Compact);

    // Send request to the server
    client.sendRequest(requestString);
}

// function to get the transaction history for an admin given an account number and count of transactions
void Admin::getTransactionHistoryAdmin(const QString &accountNumber, int count)
{
    // Create JSON request object
    QJsonObject requestObject;
    requestObject["request_type"] = "GetTransactionHistoryAdmin";

    // Add account number and count to data object
    QJsonObject dataObject;
    dataObject["account_number"] = accountNumber;
    dataObject["count"] = count;
    requestObject["data"] = dataObject;

    // Convert request object to JSON string
    QJsonDocument requestDoc(requestObject);
    QString requestString = requestDoc.toJson(QJsonDocument::Compact);

    // Send request to the server
    client.sendRequest(requestString);
}

// function to view the entire bank database
void Admin::viewBankDatabase()
{
    // Create JSON request object
    QJsonObject requestObject;
    requestObject["request_type"] = "ViewBankDataBase";

    // Convert request object to JSON string
    QJsonDocument requestDoc(requestObject);
    QString requestString = requestDoc.toJson(QJsonDocument::Compact);

    // Send request to the server
    client.sendRequest(requestString);
}

// function to delete a user given an account number
void Admin::deleteUser(const QString &Acc_Number)
{
    // Create JSON request object
    QJsonObject requestObject;
    requestObject["request_type"] = "DeleteUser";

    // Add account number to data object
    QJsonObject dataObject;
    dataObject["account_number"] = Acc_Number;
    requestObject["data"] = dataObject;

    // Convert request object to JSON string
    QJsonDocument requestDoc(requestObject);
    QString requestString = requestDoc.toJson(QJsonDocument::Compact);

    // Send request to the server
    client.sendRequest(requestString);
}

// function to add a user with given details
void Admin::addUser(const QString &username, const QString &password, const QString &fullName, const QString &age, const QString& UserEmail)
{
    // Create JSON request object
    QJsonObject requestObject;
    requestObject["request_type"] = "CreateNewUser";

    // Add user details to data object
    QJsonObject dataObject;
    dataObject["username"] = username;
    dataObject["password"] = password;
    dataObject["fullname"] = fullName;
    dataObject["age"] = age;
    dataObject["email"] = UserEmail;
    requestObject["data"] = dataObject;

    // Convert request object to JSON string
    QJsonDocument requestDoc(requestObject);
    QString requestString = requestDoc.toJson(QJsonDocument::Compact);

    // Send request to the server
    client.sendRequest(requestString);
}

// function to update a user's details given their information
void Admin::updateUser(const QString &username, const QString &password, const QString &fullName, const QString &accountNumber, const QString &age, const QString& UserEmail)
{
    // Create JSON request object
    QJsonObject requestObject;
    requestObject["request_type"] = "UpdateUserData";

    // Add updated user details to data object
    QJsonObject dataObject;
    dataObject["username"] = username;
    dataObject["password"] = password;
    dataObject["fullname"] = fullName;
    dataObject["accountNumber"] = accountNumber;
    dataObject["age"] = age;
    dataObject["email"] = UserEmail;
    requestObject["data"] = dataObject;

    // Convert request object to JSON string
    QJsonDocument requestDoc(requestObject);
    QString requestString = requestDoc.toJson(QJsonDocument::Compact);

    // Send request to the server
    client.sendRequest(requestString);
}
