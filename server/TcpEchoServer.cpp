#include "TcpEchoServer.h"
#include <QDebug>
#include <QHostAddress>

TcpEchoServer::~TcpEchoServer()
{
    mTcpServer->close();
}

TcpEchoServer::TcpEchoServer(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);

    connect(mTcpServer, &QTcpServer::newConnection, this, &TcpEchoServer::slotNewConnection);

    if (!mTcpServer->listen(QHostAddress::Any, 33333)) {
        qDebug() << "server is not started";
    } else {
        qDebug() << "server is started";
    }
}

void TcpEchoServer::slotNewConnection()
{
    mTcpSocket = mTcpServer->nextPendingConnection();
    if (!mTcpSocket) {
        qDebug() << "Failed to create socket";
        return;
    }

    mTcpSocket->write("Hello, World!!! I'm an echo server!\r\n");
    connect(mTcpSocket, &QTcpSocket::readyRead, this, &TcpEchoServer::slotServerRead);
    connect(mTcpSocket, &QTcpSocket::disconnected, this, &TcpEchoServer::slotClientDisconnected);
}

void TcpEchoServer::slotServerRead() {
    QByteArray data = mTcpSocket->readAll();
    qDebug() << "Received message:" << data;
    mTcpSocket->write("\r\n" + data);
}


void TcpEchoServer::slotClientDisconnected()
{
    if (mTcpSocket) {
        mTcpSocket->close();
    }
}
