#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStatusBar>
#include"info.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    main=this;
    b=new Board(this);
this->setFixedSize(800,495);
    b->build();
    b->show();
   // statusBar()->showMessage("hi",2000);


}

MainWindow::~MainWindow()
{
    qDebug()<<"destructor main";
    delete b;
    delete ui;
}

void MainWindow::showScore(QString &t)
{
    statusBar()->show();
    statusBar()->showMessage(t);
}
