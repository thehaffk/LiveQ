//
// Created by haffk on 19.02.2024.
//

#ifndef TCPECHOSERVER_H
#define TCPECHOSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>

class TcpEchoServer : public QObject
{
    Q_OBJECT
public:
    explicit TcpEchoServer(QObject *parent = nullptr);
    ~TcpEchoServer() override;

    public slots:
        void slotNewConnection();
    void slotServerRead();
    void slotClientDisconnected();

private:
    QTcpServer *mTcpServer;
    QTcpSocket *mTcpSocket{};
};

#endif // TCPECHOSERVER_H

