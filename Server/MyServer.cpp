#include "MyServer.h"

MyServer::MyServer(QObject *parent)
    : QTcpServer(parent), qout(stdout), qin(stdin)
{}

//function to start the server
void MyServer::StartServer()
{
    // Attempt to start the server and listen on the specified port for incoming connections
    if (this->listen(QHostAddress::Any, port))
    {
        // If the server starts successfully, print a message indicating that it is listening
        qout << "Server is up and listening on port => " << port << Qt::endl;
    }
    else
    {
        // If the server fails to start, print an error message
        qout << "Server cannot listen on port => " << port << Qt::endl;
    }
}

// function to handle incoming connections
void MyServer::incomingConnection(qintptr handle)
{
    // Print a debug message indicating that a client has connected with the given handle
    qDebug() << "Client " << handle << " connected...";

    // Create a new instance of MyServerHandler to handle the client's connection
    MyServerHandler *serverHandler = new MyServerHandler(handle, this);

    // Connect the finished signal of the serverHandler thread to the deleteLater slot,
    // so that the serverHandler object is deleted when the thread finishes
    connect(serverHandler, &QThread::finished, serverHandler, &QThread::deleteLater);

    // Start the serverHandler thread to handle client data
    serverHandler->start();
}

MyServer &MyServer::getInstance()
{
    static MyServer instance;
    return instance;
}
