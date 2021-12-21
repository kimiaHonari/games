#include "barrier.h"
#include<QPainter>
#include"info.h"
#include<QPoint>
Barrier::Barrier(float X,float Y, type T, QGraphicsItem *parent):BaseObj(parent)
 ,_type(T)
{
    x=X;y=Y;
    if(_type == Pipe)
    {
        width=60;height=120;
    }
    else
    {
     width=60;height=60;
    }
     rec=new QRect(x,y,width+3,height+3);
}

void Barrier::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap* background;
    if(_type==Ground)
    {
        background=new QPixmap(":/barrier/res/groundTop.png");
    }
    else if(_type==Block)
    {
     background=new QPixmap(":/barrier/res/block.png");
    }
    else if(_type==Pipe)
    {
        background=new QPixmap(":/barrier/res/pipe.png");
    }
    else
   background=new QPixmap(":/barrier/res/Brick.png");
    painter->drawPixmap(x,y,width,height,*background);
}

QRectF Barrier::boundingRect() const
{
    return QRectF(x,y,width+7,height);
}

int Barrier::reaction()
{

    if(_scene->_Mario->rec->top()-rec->bottom()<5 && _scene->_Mario->rec->top()-rec->bottom()>=-30)
        return 2;
    if(_scene->_Mario->rec->bottom() <= rec->top()-1)
    {

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
