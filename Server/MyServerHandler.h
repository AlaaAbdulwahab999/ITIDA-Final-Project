#ifndef MYSERVERHANDLER_H
#define MYSERVERHANDLER_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>
#include <QDateTime>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QProcess>
#include "DataBaseHandler.h"
#include <UserHandler.h>
#include <AdminHandler.h>

class MyServerHandler : public QThread
{
    Q_OBJECT

public:
    // Constructor to initialize the handler with a unique ID
    explicit MyServerHandler(int ID, QObject *parent = nullptr);

    // function  to send a message with a specific request type
    void SendMessage(const QString& message, const QString& requestType);

    // function to log a request message to Log file
    void logRequest(const QString &message);

    // Static function to encrypt a message using a given key
    static QByteArray encryptMessage(const QString &message, const QString &key);

    // Static function to decrypt a message using a given key
    static QString decryptMessage(const QString &encryptedMessage, const QString &key);

    // function to send an email with specified recipient, subject, and body
    void sendEmail(const QString &to, const QString &subject, const QString &body);

protected:
    // Override of QThread's run function to handle thread execution
    void run() override;

private slots:
    // Slot to handle incoming data from the socket
    void onReadyRead();

    // Slot to handle socket disconnection
    void onDisconnected();

private:
    int id;                          // Unique identifier for the handler
    QTcpSocket *socket;              // Socket for communication with the client
    DataBaseHandler *dbHandler;      // Handler for database operations
    QNetworkAccessManager *networkManager; // Manager for network operations
    UserHandler *userHandler;        // Handler for user operations
    AdminHandler *adminHandler;      // Handler for admin operations

    // Handles various operations based on the request type and request data
    void handleOperation(const QString &requestType, QJsonObject requestData);

    // Handles the login operation using the provided request data
    void handleLogin(const QJsonObject &requestData);

    // A helper function for additional tasks (purpose and implementation needed)
    void handleHelperFunction(void);

    // Handles the logout operation
    void handleLogout(void);

    // Initializes handlers for user, admin
    void initializeHandlers();

    QString username = "";  // Username for current user
    QString role = "";      // Role of the user ( admin, user)
    QString Email = "";     // Email address of the user
    // Path to batch script
    QString batchFilePath = "..\\..\\send_email.bat";
    // Path to the log file
    QString Log_file = "..\\..\\Request.log";



};

#endif // MYSERVERHANDLER_H
