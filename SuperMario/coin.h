#ifndef COIN_H
#define COIN_H
#include"reward.h"

class coin:public Reward
{
   QPropertyAnimation *right;
    QTimer *t;

    Q_OBJECT
    Q_PROPERTY(float move READ move WRITE setmove NOTIFY moveChanged)
public:
    coin(float X,float Y,QGraphicsItem *parent=0);

    ~coin();
    void score();
   float move(){return y;}
    void setmove(float c);
    void  set();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;
    void setcounter(int c);
signals:
    void moveChanged(float);
public slots:
    void start();
    void up();
};
#endif // COIN_H
