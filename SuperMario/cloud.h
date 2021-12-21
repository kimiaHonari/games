#ifndef CLOUD_H
#define CLOUD_H
#include "baseobj.h"
class cloud :public BaseObj
{

public:
    cloud(int x,int y,QGraphicsItem *parent=0);
    int reaction();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;
};

#endif // CLOUD_H
