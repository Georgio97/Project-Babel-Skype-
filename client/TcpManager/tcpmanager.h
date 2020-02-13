#ifndef TCPMANAGER_H
#define TCPMANAGER_H

#include <QObject>
#include <QtNetwork/QTcpSocket>
#include <iostream>
#include <memory>

class TcpManager : public QObject
{
    Q_OBJECT
    public:
        explicit TcpManager(QString &sender, quint16 &port, QObject *parent = nullptr);
        bool isConnected();
    private:
        std::unique_ptr<QTcpSocket> _socket;
        QString _sender;
        quint16 _port;
        bool _connected;

    signals:

    public slots:
};

#endif // UDPMANAGER_H
