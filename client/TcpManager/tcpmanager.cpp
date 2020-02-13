#include "tcpmanager.h"

TcpManager::TcpManager(QString &sender, quint16 &port, QObject *parent) : QObject(parent)
{
    _socket = std::unique_ptr<QTcpSocket>(new QTcpSocket);
    _sender = sender;
    _port = port;
    _socket->connectToHost(_sender, _port);
    if (!_socket->waitForConnected())
        _connected = false;
    else
        _connected = true;
}

bool TcpManager::isConnected() {
    return _connected;
}
