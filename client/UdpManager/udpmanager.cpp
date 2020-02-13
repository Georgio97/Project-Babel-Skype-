#include "udpmanager.h"

UdpManager::UdpManager(QHostAddress sender, QObject *parent) : QObject(parent)
{
    _socket = std::unique_ptr<QUdpSocket>(new QUdpSocket(this));
    _sender = sender;
    _socket->bind(_sender, 1234);
    QHostAddress senders;
    quint16 senderPort;
    QByteArray buffer;

    _socket->writeDatagram("test", _sender, 1234);
    _socket->writeDatagram("other", _sender, 1234);
    _socket->writeDatagram("otherOne", _sender, 1234);
    while (_socket->hasPendingDatagrams()) {
         buffer.resize(static_cast<int>(_socket->pendingDatagramSize()));
         _socket->readDatagram(buffer.data(), buffer.size(), &senders, &senderPort);
         qDebug() << "Message from: " << senders.toString();
         qDebug() << "Message port: " << senderPort;
         qDebug() << "Message: " << buffer;
    }
}

