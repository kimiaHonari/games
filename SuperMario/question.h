#ifndef QUESTION_H
#define QUESTION_H
#include<QImage>
#include"baseobj.h"
#include<QPropertyAnimation>
#include<QTimer>
class Question :public BaseObj
{
   QRect *rec;
   QPropertyAnimation *anim;
   QPropertyAnimation *_jump_up;
   QPropertyAnimation *_jump_down;
   QTimer *time;

    Q_OBJECT
    Q_PROPERTY(int counter READ counter WRITE setcounter NOTIFY counterChanged)
   Q_PROPERTY(float jump READ jump WRITE setjump NOTIFY jumpChanged)
public:
   enum ty{Flower,Up,Coins}_type;
    Question(float X,float Y,ty t,QGraphicsItem *parent=0);
    int _counter;
    bool type;
    int times;
    int reaction();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;
    void setcounter(int c);
    int counter(){return _counter;}
    float jump(){return y;}
    void setjump(float c);
    void move();
signals:
    void counterChanged(int);
    void jumpChanged(float);

public slots:
    void start();
};

#endif // QUESTION_H
