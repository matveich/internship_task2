#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->button_show, SIGNAL(released()), this, SLOT(handle_button_show()));
}

void MainWindow::handle_button_show() {
    const QString address = ui->textfield_address->text();
    PullTXsThread pull_thr(address);
    pull_thr.start();
}


MainWindow::~MainWindow()
{
    delete ui;
}
