#ifndef ENEMY_H
#define ENEMY_H
#include"baseobj.h"
#include<QPropertyAnimation>
#include<QTimer>
class Enemy:public BaseObj
{
    bool death;
     QRect *rec;
    Q_OBJECT
    QPropertyAnimation *right;
    QPropertyAnimation *left;
    QPropertyAnimation *anim;
    QTimer *time1;
    QTimer *time2;
    QTimer *t;

public:
    Q_PROPERTY(int counter READ counter WRITE setcounter NOTIFY counterChanged)
    Q_PROPERTY(float move READ move WRITE setmove NOTIFY moveChanged)
    bool _dir;
    int _counter;
    Enemy(float X,float Y,QGraphicsItem *parent=0);

    int reaction();
    void setcounter(int c);
    int counter(){return _counter;}
    float move(){return x;}
    void setmove(float c);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;
signals:
    void counterChanged(int);
    void moveChanged(float);
public slots:

    void change();
    void start();
    void disapear();
};

#endif // ENEMY_H
