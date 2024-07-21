#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QCryptographicHash>
#include <QDebug>
#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkRequest>
#include <QProcess>
class MyClient : public QObject
{
    Q_OBJECT
public:
    explicit MyClient(QObject *parent = nullptr);
    void ConnectToDevice(const QString &ip, qint32 port);
    void Disconnect();
    // Function to send request to the server
    void sendRequest(const QString &DataToSend);
    //function to encrypt the data
    QString encryptMessage(const QString &message, const QString &key);
    //function to decrypt the data
    QString decryptMessage(const QString &encryptedMessage, const QString &key);
signals:
    void Connection();
    void Disconnected();
    void ErrorOccurred(QAbstractSocket::SocketError socketError);
    void StateChanged(QAbstractSocket::SocketState socketState);

    void ReadyRead(const QString &requestType, const QString &message);

private slots:
    void onConnection();
    void onDisconnected();
    void onErrorOccurred(QAbstractSocket::SocketError socketError);
    void onStateChanged(QAbstractSocket::SocketState socketState);
    void onReadyRead();

private:
    QTcpSocket socket;
    qint32 port;
    QString ip;

public:
    QString Role="";
    QString Email="";

};

#endif // MYCLIENT_H
