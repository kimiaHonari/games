#ifndef FLOWER_H
#define FLOWER_H
#include"reward.h"
class flower:public Reward
{
public:
    flower(float X,float Y,QGraphicsItem *parent=0);
    void score();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;
    void setcounter(int c);
};

#endif // FLOWER_H
