#ifndef MOVABLEBARRIER_H
#define MOVABLEBARRIER_H
#include"baseobj.h"
#include<QTimer>
#include<QPropertyAnimation>
class MovableBarrier:public BaseObj
{
    Q_OBJECT
    Q_PROPERTY(float move READ move WRITE setmove NOTIFY moveChanged)
    QTimer *t;
    QRect *rec;
    bool _dir;
    bool a;
    QPropertyAnimation *anim;
public:
    MovableBarrier(bool d,int x,int y,QGraphicsItem *parent=0);
    float move(){return x;}
    void setmove(float c);
    int reaction();
    signals:
    void moveChanged(float);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;
public slots:
    void start();
};

#endif // MOVABLEBARRIER_H
