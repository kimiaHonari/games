#include "form.h"
#include "ui_form.h"
#include"information.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    scr=new QScrollArea(this);
    if(rows>11 || columns>11)
    {
        this->setFixedSize(600,600);
     scr->setGeometry(70,79,450,480);
    }
    else
    {
        this->setFixedSize((200+(columns*10)+(columns-1)*30),(220+(rows*10)+(rows-1)*30));
      scr->setGeometry(70,79,(47+(columns*10)+(columns-1)*30),(68+(rows*10)+(rows-1)*30));

    }

    QImage image(":/back/res/gameboard.jpg");
    QPalette palette;
     palette.setBrush(this->backgroundRole(), QBrush(image));
     this->setPalette(palette);
    set_turn=new QPushButton(this);
    set_turn->setGeometry(10,50,20,20);
    set_turn->setStyleSheet("*{background-color:"+color1+";}");
    score1=new QLabel(this);
    score1->setGeometry(10,20,30,20);
    score2=new QLabel(this);
    score2->setGeometry(10,80,30,20);
     score1->setStyleSheet("*{color:"+color1+"; font-size:20px;}");
      score2->setStyleSheet("*{color:"+color2+"; font-size:20px;}");
      score1->setText("0");
      score2->setText("0");

    br=new gameboard;
    br->build();
    scr->setWidget(br);



}

Form::~Form()
{
    delete ui;
    delete scr;
    delete br;
    delete set_turn;
    delete score1;
    delete score2;
}

void Form::on_mainmenu_clicked()
{
    this->close();
    rows=11;columns=11;
    name1="player1";name2="player2";
    changeuser=1;
    add->show();
}

void Form::on_exit_clicked()
{
    add->close();
   /* rows=11;columns=11;
    name1="player1";name2="player2";
    changeuser=1;*/
    this->close();
}
