#include <QCoreApplication>
#include "TcpEchoServer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TcpEchoServer server;

    return QCoreApplication::exec();
}
