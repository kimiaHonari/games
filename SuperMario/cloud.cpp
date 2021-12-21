#include "cloud.h"
#include<QPainter>
cloud::cloud(int x, int y, QGraphicsItem *parent)
    :BaseObj(parent)
{
    this->x=x;
    this->y=y;
}
int cloud::reaction()
{
    return 4;
}

void cloud::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap* background;
    background=new QPixmap(":/env/res/cloud.png");
    painter->drawPixmap(x,y,60,60,*background);
}

QRectF cloud::boundingRect() const
{
    return QRectF(x,y,60,60);
}
