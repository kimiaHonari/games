#include "coin.h"
#include<QPainter>
#include"info.h"
coin::coin(float X, float Y, QGraphicsItem *parent)
    :Reward(X,Y,parent)
{
    width=25;height=25;
    _counter=0;
    time=new QTimer(this);
    time->setInterval(1000);
    connect(time,SIGNAL(timeout()),this,SLOT(start()));
    time->start();
    t=new QTimer(this);
    t->setInterval(70);
    connect(t,SIGNAL(timeout()),this,SLOT(up()));
}

void coin::score()
{
    _scene->setscore(50);
    time->stop();
    this->hide();
}

void coin::setmove(float c)
{
    if(c==y)
        return;
    y=c;
   emit  moveChanged(c);
    update();
}
void coin::set()
{
    t->start();
}

coin::~coin()
{
}

void coin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap* background;
    int b=_counter+1;
    QString add(":/coin/res/reward/coin/");
    add.append(QString::number(b));
    add.append(".png");
    background=new QPixmap(add);
    painter->drawPixmap(x,y,width,height,*background);

}

QRectF coin::boundingRect() const
{
    return QRectF(x,y,width,height);
}

void coin::setcounter(int c)
{
    if(_counter==c && c>=6)
        return;
    _counter=c;
    emit counterChanged(c);
    update();
}

void coin::start()
{
    anim=new QPropertyAnimation(this,"counter");
    anim->setStartValue(0);
    anim->setEndValue(5);
    anim->setDuration(1000);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void coin::up()
{
    static bool p=0;
    if(!p)
    {
        right=new QPropertyAnimation(this,"move");
        right->setStartValue(y);
        right->setEndValue(y-70);
        right->setDuration(70);
        right->start(QAbstractAnimation::DeleteWhenStopped);
        p=1;
    }
    else
    {
        right=new QPropertyAnimation(this,"move");
        right->setStartValue(y);
        right->setEndValue(y+70);
        right->setDuration(70);
        right->start(QAbstractAnimation::DeleteWhenStopped);
        p=0;
        t->stop();
    }
}
