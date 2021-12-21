#include "buttongraphicsobject.h"
#include<QPainter>
#include<QPropertyAnimation>
#include<QDebug>
ButtonGraphicsObject::ButtonGraphicsObject(int width,int height,QString add,QGraphicsItem *parent) :
    QGraphicsObject(parent)
{
    this->width=width;
    this->height=height;
    _add=add;

    setAcceptHoverEvents(true);
   // this->x=x;this->y=y;
}

void ButtonGraphicsObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap background(_add);
    painter->drawPixmap(QRect(0, 0, width, height), background);
}

QRectF ButtonGraphicsObject::boundingRect() const
{
    return QRectF(0,0,width,height);
}


void ButtonGraphicsObject::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QPropertyAnimation *anim=new QPropertyAnimation(this,"scale");
    setTransformOriginPoint(boundingRect().center());
    anim->setStartValue(1);
    anim->setEndValue(1.1);
    anim->setEasingCurve(QEasingCurve::OutElastic);
    anim->setDuration(1000);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void ButtonGraphicsObject::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{

    QPropertyAnimation *anim=new QPropertyAnimation(this,"scale");
    setTransformOriginPoint(boundingRect().center());
    anim->setStartValue(1.1);
    anim->setEndValue(1);
    anim->setEasingCurve(QEasingCurve::OutElastic);
    anim->setDuration(1000);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void ButtonGraphicsObject::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}


