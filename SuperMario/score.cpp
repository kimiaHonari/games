#include "score.h"
#include<QPainter>
#include<QFont>
Score::Score(QString s, float x, float y, QGraphicsItem *parent):
    QGraphicsItem(parent)
{
    this->x=x;
    this->y=y;
    this->s=s;

}

void Score::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QFont serifFont("Times", 30, QFont::Bold);
    painter->setFont(serifFont);
    painter->drawText(x,y,200,200,Qt::AlignTop,s);
}

QRectF Score::boundingRect() const
{
    return QRectF(x,y,20,20);
}
