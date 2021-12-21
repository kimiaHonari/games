#include "flag.h"
#include"info.h"
#include<QPainter>
Flag::Flag(float X, float Y, QGraphicsItem *parent):BaseObj(parent)
{x=X;y=Y;
    width=60;
    height=60;
}

void Flag::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap* background;
    background=new QPixmap(":/flag/res/flag.png");
    painter->drawPixmap(x,y,60,60,*background);
}

QRectF Flag::boundingRect() const
{
    return QRectF(x,y,60,60);
}

int Flag::reaction()
{
    w=new WinGame;
    w->show();
    w->setscore(_scene->_score);
    _scene->win=1;
    main->close();
    return 4;

}
