//MYSERVER_H
#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTextStream>
#include <QDebug>
#include <MyServerHandler.h>

class MyServer : public QTcpServer
{
    Q_OBJECT
public:

    // Constructor for MyServer class
    explicit MyServer(QObject *parent = nullptr);

    // Function to start the server
    void StartServer();

signals:

protected:

    // Override function to handle incoming connections
    // Parameters:
    // - handle: The socket descriptor for the incoming connection
    void incomingConnection(qintptr handle) override;

private:
    // Stream for input operations
    QTextStream qin;

    // Stream for output operations
    QTextStream qout;

    // Port number on which the server listens
    qint32 port = 12356;
};

#endif // MYSERVER_H
