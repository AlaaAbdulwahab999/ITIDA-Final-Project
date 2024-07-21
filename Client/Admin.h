// Admin.h
#ifndef ADMIN_H
#define ADMIN_H

#include <QObject>
#include <QJsonObject>
#include <QString>
#include <QMessageBox>

// Forward declaration of MyClient class
class MyClient;


class Admin : public QObject
{
    Q_OBJECT
public:
    // Constructor for Admin class
    // Takes a reference to a MyClient object
    Admin(MyClient& client, QObject *parent = nullptr);

    // function to get the account number for an admin given a username
    void getAccountNumberAdmin(const QString& username);

    // function to get the balance for an admin given an account number
    void getBalanceAdmin(const QString& accountNumber);

    // function to get the transaction history for an admin given an account number and count of transactions
    void getTransactionHistoryAdmin(const QString& accountNumber, int count);

    // function to view the entire bank database
    void viewBankDatabase();

    // function to delete a user given an account number
    void deleteUser(const QString& accountNumber);

    // function to add a user with given details
    void addUser(const QString& username, const QString& password, const QString& fullName, const QString& accountNumber, const QString& age, const QString& UserEmail);

    // function to update a user's details given their information
    void updateUser(const QString& username, const QString& password, const QString& fullName, const QString& accountNumber, const QString& age, const QString& UserEmail);

private:
    MyClient& client; // Reference to a MyClient
};

#endif // ADMIN_H
