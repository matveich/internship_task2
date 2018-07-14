#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen>
#include <QDebug>
#include <QNetworkAccessManager>
#include <iostream>
#include "pulltxsthread.h"

using std::cin;
using std::cout;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void handle_button_show();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager manager;
};

#endif // MAINWINDOW_H
