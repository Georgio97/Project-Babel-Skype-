#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPalette>
#include <QMessageBox>
#include <thread>
#include <chrono>
#include "../TcpManager/tcpmanager.h"
#include "../SettingsWindow/settingswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    std::unique_ptr<TcpManager> _tcp;
    QString _ip;
    quint16 _port;
private slots:
    void on_actionAbout_triggered();

    void on_actionQuit_triggered();

    void on_actionSettings_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
