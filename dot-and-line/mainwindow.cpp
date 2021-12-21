#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"information.h"
#include<QDebug>
#include"board.h"
QString name1="player1",name2="player2",color1="rgb(245,11,11)",color2="rgb(6,6,43)";
 int rows=11;
 int columns=11;
 bool changeuser=1;
 QString color="rgb(245,11,11)";
 void changecolor(bool a)
 {
     if(a)
     {
        color=color1;
     }
     else
     {
         color=color2;
     }
 }
  QPushButton *set_turn;
  QLabel *score1,*score2;
 int count_square;
  QString score_1="0",score_2="0";
  board *add;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(900,656);
       QImage image(":/back/res/info.jpg");
       QPalette palette;
        palette.setBrush(this->backgroundRole(), QBrush(image));
        this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_player1_textChanged(const QString &arg1)
{
    name1=arg1;
}

void MainWindow::on_player2_textChanged(const QString &arg1)
{
    name2=arg1;
}

void MainWindow::on_row_textChanged(const QString &arg1)
{
    rows=arg1.toInt();
    if(rows<=0)
        rows=11;
}

void MainWindow::on_column_textChanged(const QString &arg1)
{
    columns=arg1.toInt();
    if(columns<=0)
        columns=11;
}

void MainWindow::on_play_clicked()
{
    count_square=(rows-1)*(columns-1);
    b=new Form;

    b->show();
    this->close();
}
