#include "board.h"
#include "ui_board.h"
#include<QGraphicsView>
#include"barrier.h"
#include"info.h"
#include"question.h"
#include"movablebarrier.h"
#include"enemy.h"
#include"cloud.h"
#include<QTextStream>
#include<QDebug>
#include"coin.h"
#include"flag.h"
MyGraphicScene *_scene;
bool finish=0;
bool m=0;
int cont=0;
MainWindow *main;
Board::Board(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Board)
{
    finish=0;
    this->setFixedSize(800,600);
   view=new QGraphicsView(this);
    view->setGeometry(0,0,2002,602);
   // MyGraphicScene *s=;
    _scene=new MyGraphicScene(0);
    view->setScene(_scene);
   _scene->setSceneRect(0,0,2000,600);

   file=new QFile(":/level/res/level/level1.txt");

    ui->setupUi(this);
}

Board::~Board()
{
    delete _scene;
    delete view;

    delete ui;
}

void Board::build()
{
    if(!file->open(QFile::ReadOnly))
        return;
    QTextStream r(file);
    int wid=0,height=0,tedad=0;
    r>>wid>>height>>tedad;
    wid+=1400;
    int x=680;
    int y=0;
    _scene=new MyGraphicScene(x);
  view->setScene(_scene);
    for(int i=0;i<720;i+=60)
    {
        _scene->addItem(new Barrier(x,i,Barrier::Brike));
    }
    _scene->setSceneRect(x,0,wid,height);
     view->setGeometry(0,0,wid+3,height+3);
     x+=60;
     int counter=0;
    while(!r.atEnd())
    {
        int num=0;
        r>>num;
       // qDebug()<<num;
        counter++;
        if(counter==tedad)
        {
            x=700;
            y+=60;
            counter=0;
        }
        if(num==1)
            _scene->addItem(new Barrier(x,y,Barrier::Ground));

        if(num==2)
            _scene->addItem(new Barrier(x,y,Barrier::Brike));

        if(num==3)
            _scene->addItem(new Barrier(x,y,Barrier::Block));
        if(num==4)
            _scene->addItem(new Question(x,y,Question::Up));
        if(num==5)
            _scene->addItem(new Question(x,y,Question::Flower));

        if(num==6)
            _scene->addItem(new Question(x,y,Question::Coins));

        if(num==7)
        {
           // y-=10;
            _scene->addItem(new Enemy(x,y));
            //y+=10;
        }

        if(num==8)
            _scene->addItem(new MovableBarrier(0,x,y));

        if(num==9)
            _scene->addItem(new MovableBarrier(1,x,y));

        if(num==10)
            _scene->addItem(new coin(x,y));

        if(num==11)
            _scene->addItem(new cloud(x,y));

        if(num==12)
        {
            _scene->addItem(new Flag(x,y));
            continue;
        }
        if(num==13)
        {
            _scene->addItem(new Barrier(x,y,Barrier::Pipe));
        }
        x+=60;
    }
  /*  for(int i=0;i<1200;i+=80)
    {
        _scene->addItem(new Barrier(i,500,Barrier::Ground));
    }*/
    //_scene->addItem(new Barrier(0,100,300));
}




