#ifndef USER_H
#define USER_H

#include <QObject>
#include <QJsonObject>
#include <QString>

// Forward declaration of the MyClient class
class MyClient;

class User : public QObject
{
    Q_OBJECT
public:
    // Constructor for the User class, takes a MyClient reference
    User(MyClient& client, QObject *parent = nullptr);

    // Function to request the account number based on the username
    void getAccountNumber(const QString& username);

    // Function to request the balance of an account based on the account number
    void getBalance(const QString& accountNumber);

    // Function to request the transaction history of an account
    void getTransactionHistory(const QString& accountNumber, int count);

    // Function to withdraw an amount from an account
    void withdraw(const QString& accountNumber, double amount);

    // Function to deposit an amount into an account
    void deposit(const QString& accountNumber, double amount);

    // Function to transfer an amount from one account to another
    void transfer(const QString& fromAccount, const QString& toAccount, double amount);

private:
    // Reference to the MyClient object used for sending requests
    MyClient& client;
};

#endif // USER_H
