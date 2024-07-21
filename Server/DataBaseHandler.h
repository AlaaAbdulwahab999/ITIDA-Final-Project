#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDate>
#include <QVector>

// Structure to represent a financial transaction
struct Transaction
{
    QDate date;      // Date of the transaction
    double amount;   // Amount of money involved in the transaction
    QString type;    // Type of transaction (e.g., "deposit" or "withdrawal")
};

// Enum to represent the status of user creation operations
enum UserCreationStatus
{
    Success,                  // User was successfully created
    InvalidAccountNumber,     // Account number is invalid (non-numeric or improperly formatted)
    UserAlreadyExists         // User already exists with the given account number or username
};

// Enum to represent the status of user update operations
enum UserUpdateStatus
{
    SuccessUpdate,            // User information was successfully updated
    UsernameAlreadyExists,    // New username is already taken by another user
    AccountNotFound           // Account with the specified number does not exist
};

class DataBaseHandler : public QObject
{
    Q_OBJECT
public:
    // Constructor for the DataBaseHandler class
    explicit DataBaseHandler(QObject *parent = nullptr);

    // Authenticates a user with the given username and password
    bool login(const QString& username, const QString& password);

    // get the account number associated with the given username
    QString getAccountNumber(const QString& username);

    // get the current balance of the specified account number
    int getBalance(const QString& accountNumber);

    // Makes a transaction of the specified amount on the given account number
    bool makeTransaction(const QString& accountNumber, int amount);

    // get the transaction history for the specified account number, limited to the most recent 'count' transactions
    QJsonObject getTransactionHistory(const QString& accountNumber, int count);

    // Transfers the specified amount from one account to another
    bool transferAmount(const QString& fromAN, const QString& toAN, int amount);

    // Creates a new user with the given user data in JSON format
    UserCreationStatus createNewUser(QJsonObject userData);

    // Deletes the user associated with the specified account number
    bool deleteUser(const QString& accountNumber);

    // Updates the user information for the specified account number with the new data in JSON format
    UserUpdateStatus updateUser(const QString& accountNumber, const QJsonObject& newData);

    // get the entire bank database as a vector of JSON objects
    QVector<QJsonObject> viewBankDatabase();

    // Retrieves the role of the user with the given username
    QString getUserRole(const QString& username);

    // get the user information as a JSON object for the specified account number
    QJsonObject getUserObjectByAccountNumber(const QString& accountNumber);

    //Check account number Exists
    bool accountNumberExists(const QString& accountNumber);

    // get the user information as a JSON object for the given username
    QJsonObject getUserObject(const QString &username);

    // get the email address associated with the specified account number
    QString getUserEmail(const QString& accountNumber);

    // get the username associated with the specified account number
    QString getUserName(const QString &accountNumber);

    // Deposits the specified amount into the given account number
    bool depositAmount(const QString& accountNumber, double amount);

    // Withdraws the specified amount from the given account number
    bool withdrawAmount(const QString& accountNumber, double amount);


private:
    // Reads a JSON array from the specified file
    QJsonArray readJsonArrayFromFile(const QString& fileName);

    // Writes the given JSON array to the specified file
    void writeJsonArrayToFile(const QString& fileName, const QJsonArray& jsonArray);

    // get the transaction array for the specified account number
    QJsonArray getTransactionArray(const QString& accountNumber);

    QString loginFile = "..\\..\\..\\DataBase\\Login.json";
    QString transactionFile = "..\\..\\..\\DataBase\\Transaction.json";
};

#endif // DATABASEHANDLER_H
