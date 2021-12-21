#ifndef FLAG_H
#define FLAG_H
#include "baseobj.h"
#include"wingame.h"
class Flag :public BaseObj
{
    WinGame *w;
public:
    Flag(float x,float y,QGraphicsItem *parent=0);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;
    int reaction();
};

#endif // FLAG_H
