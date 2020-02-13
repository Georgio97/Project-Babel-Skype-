#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _ip = QString("127.0.0.1");
    _port = 1234;
    _tcp = std::unique_ptr<TcpManager>(new TcpManager(_ip, _port));

    if (!_tcp->isConnected()) {
        QMessageBox::critical(this, "Warning", "Can't reach the Server try to reload the application !");
        ui->statusLabel->setText("<p style='color: red'>not connected</p>");
    } else
        ui->statusLabel->setText("<p style='color: green'>connected</p>");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "About us", "Developers:\n  Client-Side: Gautier & XxNordAlguinxX\n  Server-Side: Lucas");
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionSettings_triggered()
{
    QMessageBox::information(this, "Setings", "Here you can change the ip of Server");
}
