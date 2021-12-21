#ifndef BARRIER_H
#define BARRIER_H
#include"baseobj.h"
#include<QRect>
class Barrier:public BaseObj
{
  // int x,y,width,height;
   QRect *rec;
  public:
    enum type{Ground,Block,Brike,Pipe}_type;
    Barrier(float X,float Y,type T=Ground,QGraphicsItem *parent=0);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;
    int reaction();
};

#endif // BARRIER_H
