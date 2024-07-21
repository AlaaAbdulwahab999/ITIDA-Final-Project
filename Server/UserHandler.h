#ifndef USERHANDLER_H
#define USERHANDLER_H

#include <QObject>
#include <QString>
#include <QJsonObject>

class DataBaseHandler;  // Forward declaration of the DataBaseHandler class

class UserHandler : public QObject {
    Q_OBJECT

public:
    /**
     *  Constructs a UserHandler object.
     *  dbHandler Pointer to the DataBaseHandler instance used for database operations.
     *  username The username of the current user.
     *  email The email address of the current user.
     */
    UserHandler(DataBaseHandler* dbHandler, const QString& username, const QString& email, QObject* parent = nullptr);

    //function to handle retrieving the account number for the given username.
    void handleGetAccountNumber(const QString& username);

    // function to handle retrieving the balance for a given account number.
    void handleGetBalance(const QString& accountNumber);

    //  function to handle retrieving transaction history for an account.
    void handleGetTransactionHistory(const QJsonObject& requestData);

    // function to handle withdrawal requests.
    void handleWithdraw(const QJsonObject& requestData);
    // function to handle deposite requests.

    void handleDeposit(const QJsonObject& requestData);

    // function to handle transfer requests.
    void handleTransferAmount(const QJsonObject& requestData);

signals:
    // Signal to send a message to the client
    void sendMessage(const QString& message, const QString& operation);
    //Signal to log a request message
    void logRequest(const QString& logMessage);
    //Signal to send an email.
    void sendEmail(const QString& email, const QString& subject, const QString& body);

private:
    DataBaseHandler* dbHandler;
    QString _username;
    QString Email;
};

#endif // USERHANDLER_H
