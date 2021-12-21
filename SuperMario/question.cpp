#include "question.h"
#include"info.h"
#include<QPainter>
#include<QPixmap>
#include<QString>
#include<QDebug>
#include"mashroom.h"
#include"flower.h"
#include<QAnimationGroup>
#include"coin.h"
Question::Question(float X, float Y,ty t, QGraphicsItem *parent):BaseObj(parent)
{
    _type=t;
    width=60,height=60;
    x=X;
    y=Y;
    _counter=0;
    type=0;times=0;
    rec=new QRect(x,y,width,height);

    time=new QTimer(this);
    time->setInterval(1000);
    connect(time,SIGNAL(timeout()),this,SLOT(start()));
    time->start();

}

int Question::reaction()
{

     if(_scene->_Mario->rec->top()-rec->bottom()<5 && _scene->_Mario->rec->top()-rec->bottom()>=-20)
     {

         times++;
         qDebug()<<times<<"times";
         if(!type)
         move();
         if(times==4)
         {
             type=1;
             if(_type==Up)
             {
                 _scene->addItem(new Mashroom(x+5,y-61));

             }
             if(_type==Flower)
                 _scene->addItem(new flower(x+5,y-61));
             if(_type==Coins)
             {
                 coin *n=new coin(x+5,y-70);
                 _scene->addItem(n );
                // n->set();

             }
         }
         return 2;
     }
     if(_scene->_Mario->rec->bottom() <= rec->top()-1)
     {
         return 3;
     }
     if(_scene->_Mario->rec->bottom()> rec->top()+1)
     {
         int xr=_scene->_Mario->rec->bottomRight().x();
         int xy=_scene->_Mario->rec->bottomLeft().x();

         if(xr-rec->bottomLeft().x()<=50 && xr-rec->bottomLeft().x()>=-10)
             return 0;

         if(xy-rec->bottomRight().x()<=10 && xy-rec->bottomRight().x()>=-50)
             return 1;
     }

}

void Question::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap* background;
    if(type)
    {
        time->stop();
        background=new QPixmap(":/question/res/Question block frames/empty block.png");
    }
    else
    {
        //qDebug()<<_counter<<"counter";
        int b=_counter+1;
        QString add(":/question/res/Question block frames/");
        add.append(QString::number(b));
        add.append(".png");
        background=new QPixmap(add);
    }
    painter->drawPixmap(x,y,width,height,*background);
}

QRectF Question::boundingRect() const
{
    return QRectF(x,y,width,height);
}

void Question::setcounter(int c)
{
    if(_counter==c && c>=27)
        return;
    _counter=c;
    emit counterChanged(c);
    update();
}

void Question::setjump(float c)
{
    if(y==c)
        return;
    y=c;
    emit jumpChanged(c);
    update();
}

void Question::move()
{
    _jump_up=new QPropertyAnimation(this,"jump");
    _jump_up->setStartValue(y);
    _jump_up->setEndValue(y-0.55);
    _jump_up->setEasingCurve(QEasingCurve::OutElastic);
    _jump_up->setDuration(1000);
    _jump_up->start(QAbstractAnimation::DeleteWhenStopped);

    _jump_down=new QPropertyAnimation(this,"jump");
    _jump_down->setStartValue(y);
    _jump_down->setEndValue(y+10);
    _jump_down->setEasingCurve(QEasingCurve::OutElastic);
    _jump_down->setDuration(1000);
   // _jump_down->start(QAbstractAnimation::DeleteWhenStopped);



}


void Question::start()
{
    anim=new QPropertyAnimation(this,"counter");
    anim->setStartValue(0);
    anim->setEndValue(26);
    anim->setDuration(1000);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}
