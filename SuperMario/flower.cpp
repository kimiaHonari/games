#include "flower.h"
#include<QPainter>
#include"info.h"
flower::flower(float X, float Y, QGraphicsItem *parent)
    :Reward(X,Y,parent)
{
    width=40;height=40;
    _counter=0;
    anim=new QPropertyAnimation(this,"counter");
    anim->setStartValue(0);
    anim->setEndValue(11);
    anim->setDuration(1000);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void flower::score()
{
    _scene->setscore(300);
    this->hide();
}

void flower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap* background;
    int b=_counter+1;
    QString add(":/flower/res/reward/flower/");
    add.append(QString::number(b));
    add.append(".png");
    background=new QPixmap(add);
    painter->drawPixmap(x,y,width,height,*background);
}

QRectF flower::boundingRect() const
{
     return QRectF(x,y,width,height);
}

void flower::setcounter(int c)
{
    if(_counter==c && c>=12)
        return;
    _counter=c;
    emit counterChanged(c);
    update();
}
