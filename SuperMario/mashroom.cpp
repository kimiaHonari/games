#include "mashroom.h"
#include<QPainter>
#include"info.h"
Mashroom::Mashroom(float X, float Y, QGraphicsItem *parent)
    :Reward(X,Y,parent)
{
    width=40;height=40;
    _counter=0;
    anim=new QPropertyAnimation(this,"counter");
    anim->setStartValue(0);
    anim->setEndValue(16);
    anim->setDuration(1000);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void Mashroom::score()
{
    this->hide();
    _scene->_Mario->bigger();
}

void Mashroom::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap* background;
    int b=_counter+1;
    QString add(":/up/res/reward/up/");
    add.append(QString::number(b));
    add.append(".png");
    background=new QPixmap(add);
    painter->drawPixmap(x,y,width,height,*background);
}

QRectF Mashroom::boundingRect() const
{
    return QRectF(x,y,width,height);
}

void Mashroom::setcounter(int c)
{
    if(_counter==c && c>=17)
        return;
    _counter=c;
    emit counterChanged(c);
    update();
}
