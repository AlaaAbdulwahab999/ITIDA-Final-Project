#ifndef ADMINHANDLER_H
#define ADMINHANDLER_H

#include <QObject>
#include <QJsonObject>
#include "DataBaseHandler.h"

class AdminHandler : public QObject {
    Q_OBJECT

public:
    // Constructor for the AdminHandler class
    explicit AdminHandler(DataBaseHandler *dbHandler, const QString &username, QObject *parent = nullptr);

    // Handles get the account number for an admin user using the provided request data
    void handleGetAccountNumberAdmin(const QJsonObject &requestData);

    // Handles updating user information using the provided request data
    void handleUserUpdate(const QJsonObject &requestData);

    // Handles the deletion of a user with the specified account number
    void handleDeleteUser(const QString &accountNumber);

    // Handles creating a new user with the provided request data
    void handleCreateNewUser(QJsonObject &requestData);

    // Handles get the balance for the specified account number
    void handleGetBalanceAdmin(const QString &accountNumber);

    // Handles get the transaction history using the provided request data
    void handleGetTransactionHistoryAdmin(const QJsonObject &requestData);

    // Handles viewing the entire bank database
    void handleViewBankDatabase();

signals:

    // Signal to send a message with a specific request type
    // Parameters:
    // - message: The message to be sent
    // - requestType: The type of request that generated this message
    void sendMessage(const QString &message, const QString &requestType);

private:

    // Pointer to the database handler used for database operations
    DataBaseHandler *dbHandler;
    QString username;
};

#endif // USERHANDLER_H
