#ifndef REWARD_H
#define REWARD_H
#include"baseobj.h"
#include<QPropertyAnimation>
#include<QTimer>
class Reward :public BaseObj
{
    Q_OBJECT
public:
    QPropertyAnimation *anim;
   // QPropertyAnimation *jump;
    QTimer *time;
    Q_PROPERTY(int counter READ counter WRITE setcounter NOTIFY counterChanged)
    int _counter;
    Reward(float X,float Y,QGraphicsItem *parent=0);
    int reaction();
    virtual void score()=0;
private:
    virtual void setcounter(int c)=0;
    int counter(){return _counter;}
signals:
    void counterChanged(int);
};

#endif // REWARD_H
