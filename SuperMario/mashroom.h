#ifndef MASHROOM_H
#define MASHROOM_H
#include"reward.h"
class Mashroom:public Reward
{
public:
    Mashroom(float X,float Y,QGraphicsItem *parent=0);
    void score();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;
    void setcounter(int c);
};

#endif // MASHROOM_H
