#ifndef UDPMANAGER_H
#define UDPMANAGER_H

#include <QObject>
#include <QtNetwork/QUdpSocket>
#include <iostream>
#include <memory>

class UdpManager : public QObject
{
    Q_OBJECT
    public:
        explicit UdpManager(QHostAddress sender = QHostAddress::LocalHost, QObject *parent = nullptr);
    private:
        std::unique_ptr<QUdpSocket> _socket;
        QHostAddress _sender;

    signals:

    public slots:
};

#endif // UDPMANAGER_H
