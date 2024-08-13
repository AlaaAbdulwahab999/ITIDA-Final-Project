
#include <QCoreApplication>
#include "MyServer.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    MyServer& server= MyServer::getInstance();
    server.StartServer();
    return a.exec();
}

