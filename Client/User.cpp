#include "User.h"
#include "MyClient.h"

// Constructor for the User class
User::User(MyClient& client, QObject *parent)
    : QObject(parent), client(client) {}

// function to get the account number based on the username
void User::getAccountNumber(const QString& username)
{
    // Prepare the JSON request object
    QJsonObject requestObject;
    requestObject["request_type"] = "GetAccountNumber";

    QJsonObject dataObject;
    dataObject["username"] = username;
    requestObject["data"] = dataObject;

    // Convert the JSON object to a JSON document
    QJsonDocument requestDoc(requestObject);
    // Convert the JSON document to a compact string
    QString requestString = requestDoc.toJson(QJsonDocument::Compact);

    // Send the request to the server
    client.sendRequest(requestString);
}

// function to get the balance based on the account number
void User::getBalance(const QString &accountNumber)
{
    // Prepare the JSON request object
    QJsonObject requestObject;
    requestObject["request_type"] = "GetBalance";

    QJsonObject dataObject;
    dataObject["account_number"] = accountNumber;
    requestObject["data"] = dataObject;

    // Convert the JSON object to a JSON document
    QJsonDocument requestDoc(requestObject);
    // Convert the JSON document to a compact string
    QString requestString = requestDoc.toJson(QJsonDocument::Compact);

    // Send the request to the server
    client.sendRequest(requestString);
}

// function to get the transaction history for an account number
void User::getTransactionHistory(const QString &accountNumber, int count)
{
    // Prepare the JSON request object
    QJsonObject requestObject;
    requestObject["request_type"] = "GetHistory";

    QJsonObject dataObject;
    dataObject["account_number"] = accountNumber;
    dataObject["count"] = count;
    requestObject["data"] = dataObject;

    // Convert the JSON object to a JSON document
    QJsonDocument requestDoc(requestObject);
    // Convert the JSON document to a compact string
    QString requestString = requestDoc.toJson(QJsonDocument::Compact);

    // Send the request to the server
    client.sendRequest(requestString);
}

// function to withdraw an amount from an account
void User::withdraw(const QString &accountNumber, double amount)
{
    // Prepare the JSON request object
    QJsonObject requestObject;
    requestObject["request_type"] = "Withdraw";

    QJsonObject dataObject;
    dataObject["account_number"] = accountNumber;
    dataObject["amount"] = amount; // Use double for the amount
    requestObject["data"] = dataObject;

    // Convert the JSON object to a JSON document
    QJsonDocument requestDoc(requestObject);
    // Convert the JSON document to a compact string
    QString requestString = requestDoc.toJson(QJsonDocument::Compact);

    // Send the request to the server
    client.sendRequest(requestString);
}

// function to deposit an amount into an account
void User::deposit(const QString &accountNumber, double amount)
{
    // Prepare the JSON request object
    QJsonObject requestObject;
    requestObject["request_type"] = "Deposit";

    QJsonObject dataObject;
    dataObject["account_number"] = accountNumber;
    dataObject["amount"] = amount; // Use double for the amount
    requestObject["data"] = dataObject;

    // Convert the JSON object to a JSON document
    QJsonDocument requestDoc(requestObject);
    // Convert the JSON document to a compact string
    QString requestString = requestDoc.toJson(QJsonDocument::Compact);

    // Send the request to the server
    client.sendRequest(requestString);
}

// function to transfer an amount from one account to another
void User::transfer(const QString &fromAccount, const QString &toAccount, double amount)
{
    // Prepare the JSON request object for the Transfer operation
    QJsonObject requestObject;
    requestObject["request_type"] = "TransferAmount";

    QJsonObject dataObject;
    dataObject["from_account"] = fromAccount;
    dataObject["to_account"] = toAccount;
    dataObject["amount"] = amount; // Use double for the amount
    requestObject["data"] = dataObject;

    // Convert the JSON object to a JSON document
    QJsonDocument requestDoc(requestObject);
    // Convert the JSON document to a compact string
    QString requestString = requestDoc.toJson(QJsonDocument::Compact);

    // Send the request to the server
    client.sendRequest(requestString);
}
