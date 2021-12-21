#include "board.h"
#include "ui_board.h"
#include"information.h"
#include<QPalette>
#include"mainwindow.h"
board::board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::board)
{
    ui->setupUi(this);
    add=this;
 this->setFixedSize(900,600);
    QImage image(":/back/res/menu.jpg");
    QPalette palette;
     palette.setBrush(this->backgroundRole(), QBrush(image));
     this->setPalette(palette);
     //ui->newgame->setIcon(":/back/res/newgame.png");
}

board::~board()
{
    delete ui;
}

void board::on_exitgame_clicked()
{
    this->close();
}

void board::on_newgame_clicked()
{
   info=new MainWindow;
   info->show();
   this->hide();
}

void board::on_howtoplay_clicked()
{
    how=new about;
    how->show();
    this->hide();
}


