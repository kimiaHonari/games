#include "movablebarrier.h"
#include<QPainter>
#include"info.h"
#include<QDebug>
MovableBarrier::MovableBarrier(bool d,int x, int y, QGraphicsItem *parent)
    :BaseObj(parent)
{

    _dir=d;
    a=0;
    this->x=x;
    this->y=y;
    width=150;
    height=30;
    t=new QTimer(this);
    connect(t,SIGNAL(timeout()),this,SLOT(start()));
    t->setInterval(4000);
    t->start();
    rec=new QRect(x,y,width,height);
}

void MovableBarrier::setmove(float c)
{
    if(c==x)return;
    if(m &a)
    {
        _scene->_Mario->move((c-x),0);
       // _scene->x+=(c-x);
       // _scene->cur_x=x;
       // _scene->setSceneRect(_scene->cur_x,0,_scene->width(),_scene->height());
        _scene->update();
    }

    if(!m)
        a=0;
    x=c;
    emit  moveChanged(c);
    update();
}

int MovableBarrier::reaction()
{
    if(_scene->_Mario->rec->top()-rec->bottom()<5 && _scene->_Mario->rec->top()-rec->bottom()>=-30)
        return 2;
    if(_scene->_Mario->rec->bottom() <= rec->top()-1)
    {
         m=1;
         a=1;
         qDebug()<<m;
        return 3;
    }
    if(_scene->_Mario->rec->bottom()> rec->top()+1)
    {
        int xr=_scene->_Mario->rec->bottomRight().x();
        int xy=_scene->_Mario->rec->bottomLeft().x();
        //qDebug()<<xr<<xy<<xr-rec->bottomLeft().x()<<xy-rec->bottomRight().x();
        if(xr-rec->bottomLeft().x()<=50 && xr-rec->bottomLeft().x()>=-10)
            return 0;

        if(xy-rec->bottomRight().x()<=10 && xy-rec->bottomRight().x()>=-50)
            return 1;
    }
}

void MovableBarrier::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    rec->moveTo(x,y);
    QPixmap* background;
    background=new QPixmap(":/barrier/res/groundTop.png");
    painter->drawPixmap(x,y,width,height,*background);
}

QRectF MovableBarrier::boundingRect() const
{
    return QRectF(x,y,width,height);
}

void MovableBarrier::start()
{
    if(!_dir)
    {
        anim=new QPropertyAnimation(this,"move");
        anim->setStartValue(x);
        anim->setEndValue(x+300);
        anim->setDuration(4000);
        anim->start(QAbstractAnimation::DeleteWhenStopped);
        _dir=1;

    }
    else
    {
        anim=new QPropertyAnimation(this,"move");
        anim->setStartValue(x);
        anim->setEndValue(x-300);
        anim->setDuration(4000);
       anim->start(QAbstractAnimation::DeleteWhenStopped);
       _dir=0;

    }
}
