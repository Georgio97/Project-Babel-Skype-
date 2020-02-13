#include <QApplication>
#include <QtWidgets>
#include <QtNetwork/QTcpSocket>
#include <iostream>
#include "MainWindow/mainwindow.h"
#include "UdpManager/udpmanager.h"
#include "TcpManager/tcpmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
