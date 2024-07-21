#include "UserHandler.h"
#include <QDebug>
#include <QJsonDocument>
#include "DataBaseHandler.h"  // Include the DataBaseHandler header
#include <QDebug>
UserHandler::UserHandler(DataBaseHandler* dbHandler, const QString& username, const QString& email, QObject* parent)
    : QObject(parent), dbHandler(dbHandler), _username(username), Email(email) {

}
//function to handle get account number request request
void UserHandler::handleGetAccountNumber(const QString& username)
{
    QString accountNumber;
    QString role = dbHandler->getUserRole(_username);
    if (role == "user")
    {
        if (username == _username) {
            accountNumber = dbHandler->getAccountNumber(username);
            if (!accountNumber.isEmpty()) {
                // Send the account number of the current user to the client.
                emit sendMessage("Your account number: " + accountNumber, "GetAccountNumber");
            } else
            {
                // Notify the client that no account was found for their username.
                emit sendMessage("No account found for your username.", "GetAccountNumber");
            }
        }
        else
        {
            // Deny access if the user tries to request an account number for a different username.
            emit sendMessage("Access denied. You can only request your own account number.", "GetAccountNumber");
        }
    }
    else
    {
        // If the user is not a regular user, do nothing
        return;
    }
}

//function to handle get balance  request
void UserHandler::handleGetBalance(const QString& accountNumber)
{
    // Retrieve the role of the current user from the database
    QString userRole = dbHandler->getUserRole(_username);

    // Check if the current user is a regular user
    if (userRole == "user")
    {
        // Regular users can only get the balance for their own account number
        QString userAccountNumber = dbHandler->getAccountNumber(_username);

        // Verify that the provided account number matches the user's account number
        if (userAccountNumber == accountNumber)
        {
            // Retrieve the balance for the specified account number
            int balance = dbHandler->getBalance(accountNumber);

            // Send the balance information to the client
            emit sendMessage("Your balance: " + QString::number(balance), "GetBalance");
        }
        else
        {
            // Send an access denied message if the account number does not match
            emit sendMessage("Access denied. You can only request the balance for your own account.", "GetBalance");
        }
    }
    else
    {
        // If the user is not a regular user, do nothing
        return;
    }
}

//function to handle get transction history request
void UserHandler::handleGetTransactionHistory(const QJsonObject& requestData)
{
    // Extract the account number and the number of transactions to retrieve from the request data
    QString accountNumber = requestData["account_number"].toString();
    int count = requestData["count"].toInt();

    // Retrieve the role of the current user from the database
    QString userRole = dbHandler->getUserRole(_username);

    // Check if the current user is a regular user
    if (userRole == "user")
    {
        // Regular users can only get the transaction history for their own account number
        QString userAccountNumber = dbHandler->getAccountNumber(_username);

        // Verify that the provided account number matches the user's account number
        if (userAccountNumber == accountNumber)
        {
            // Retrieve the transaction history for the specified account number and count
            QJsonObject history = dbHandler->getTransactionHistory(accountNumber, count);

            // Convert the transaction history to a JSON document and then to a formatted string
            QJsonDocument doc(history);
            QString jsonString = doc.toJson(QJsonDocument::Indented);

            // Send the transaction history to the client
            emit sendMessage(jsonString, "GetHistory");
        }
        else
        {
            // Send an access denied message if the account number does not match
            emit sendMessage("Access denied. You can only request the transaction history for your own account.", "GetHistory");
        }
    }
    else
    {
        // If the user is not a regular user, do nothing
        return;
    }
}

//function to handle the withdraw request
void UserHandler::handleWithdraw(const QJsonObject& requestData)
{
    QString accountNumber = requestData["account_number"].toString();
    double amount = requestData["amount"].toDouble();

    if (_username == dbHandler->getUserName(accountNumber)) {
        // Check if the amount is valid
        if (amount <= 0) {
            emit sendMessage("Invalid withdrawal amount. Must be greater than zero.", "Withdraw");
            return;
        }

        // Check if the account number exists and retrieve the current balance
        double currentBalance = dbHandler->getBalance(accountNumber);
        if (currentBalance == -1) {
            emit sendMessage("Account number does not exist.", "Withdraw");
            return;
        }

        // Check if there are sufficient funds
        if (currentBalance < amount) {
            emit sendMessage("Insufficient funds for withdrawal.", "Withdraw");
            return;
        }

        // Perform the withdrawal
        bool success = dbHandler->withdrawAmount(accountNumber, amount);
        if (success) {
            emit sendMessage("Withdrawal successful! New balance: " + QString::number(currentBalance - amount), "Withdraw");
            QString logMessage = QString("Withdrawal of %1 from account %2 successful. New balance: %3")
                                     .arg(amount).arg(accountNumber).arg(currentBalance - amount);
            emit logRequest(logMessage);

            // Send email notification
            QString emailSubject = "Withdrawal Successful";
            QString emailBody = QString("Dear customer, your withdrawal of %1 has been successful. New balance: %2")
                                    .arg(amount).arg(currentBalance - amount);
            emit sendEmail(Email, emailSubject, emailBody);
        } else {
            emit sendMessage("Failed to withdraw amount. Please try again later.", "Withdraw");
        }
    } else {
        emit sendMessage("Access denied. You can only withdraw from your own account.", "Withdraw");
    }
}

//function to handle the deposite request
void UserHandler::handleDeposit(const QJsonObject& requestData)
{
    QString accountNumber = requestData["account_number"].toString();
    double amount = requestData["amount"].toDouble();

    if (_username == dbHandler->getUserName(accountNumber)) {
        // Check if the amount is valid
        if (amount <= 0) {
            emit sendMessage("Invalid deposit amount. Must be greater than zero.", "Deposit");
            return;
        }

        // Check if the account number exists
        double currentBalance = dbHandler->getBalance(accountNumber);
        if (currentBalance == -1)
        {
            emit sendMessage("Account number does not exist.", "Deposit");
            return;
        }

        // Perform the deposit
        bool success = dbHandler->depositAmount(accountNumber, amount);
        if (success) {
            emit sendMessage("Deposit successful! New balance: " + QString::number(currentBalance + amount), "Deposit");
            QString logMessage = QString("Deposit of %1 to account %2 successful. New balance: %3")
                                     .arg(amount).arg(accountNumber).arg(currentBalance + amount);
            emit logRequest(logMessage);

            // Send email notification
            QString emailSubject = "Deposit Successful";
            QString emailBody = QString("Dear customer, your deposit of %1 has been successful. New balance: %2")
                                    .arg(amount).arg(currentBalance + amount);
            emit sendEmail(Email, emailSubject, emailBody);
        } else
        {
            emit sendMessage("Failed to deposit amount. Please try again later.", "Deposit");
        }
    }
    else
    {
        emit sendMessage("Access denied. You can only deposit into your own account.", "Deposit");
    }
}

//function to handle the transfer request
void UserHandler::handleTransferAmount(const QJsonObject& requestData)
{
    QString fromAccount = requestData["from_account"].toString();
    QString toAccount = requestData["to_account"].toString();
    double amount = requestData["amount"].toDouble();

    // Check if the transfer is from the user's own account
    if (_username == dbHandler->getUserName(fromAccount)) {
        // Check if the amount is valid
        if (amount <= 0) {
            emit sendMessage("Invalid transfer amount. Must be greater than zero.", "TransferAmount");
            return;
        }

        // Check if the from and to account numbers are valid
        double fromBalance = dbHandler->getBalance(fromAccount);
        if (fromBalance == -1) {
            emit sendMessage("From account number does not exist.", "TransferAmount");
            return;
        }

        double toBalance = dbHandler->getBalance(toAccount);
        if (toBalance == -1) {
            emit sendMessage("Host account number does not exist.", "TransferAmount");
            return;
        }

        // Check if there are sufficient funds in the from account
        if (fromBalance < amount) {
            emit sendMessage("Insufficient funds for transfer.", "TransferAmount");
            return;
        }

        // Perform the transfer
        bool success = dbHandler->transferAmount(fromAccount, toAccount, amount);
        if (success) {
            emit sendMessage("Transfer successful!", "TransferAmount");
            QString logMessage = QString("Transfer of %1 from account %2 to account %3 successful!")
                                     .arg(amount).arg(fromAccount).arg(toAccount);
            emit logRequest(logMessage);

            // Send email notification
            QString emailSubject = "Transfer Successful";
            QString emailBody = QString("Transfer of %1 from account %2 to account %3 successful!")
                                    .arg(amount).arg(fromAccount).arg(toAccount);
            emit sendEmail(Email, emailSubject, emailBody);
        } else {
            emit sendMessage("Transfer failed.", "TransferAmount");
        }
    } else {
        emit sendMessage("Access denied. You can only transfer from your own account.", "TransferAmount");
    }
}
