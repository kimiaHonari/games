#ifndef MARIO_H
#define MARIO_H
#include<QGraphicsItem>
#include<QList>
#include<QGraphicsObject>
#include<QPicture>
#include<QPropertyAnimation>
#include<QTimer>
class mario:public QGraphicsObject
{
    int counter;
     QPropertyAnimation *anim;
    Q_OBJECT
     Q_PROPERTY(int size READ size WRITE setsize NOTIFY sizeChanged)
      float x,y; float width,height;float _size;
public:
     int nu_pic;
    bool stop;
    QRect *rec;
    QTimer *time;
    float Vx,Vy;
    bool direct;  
    bool right,left,up,down,jump;
    bool big;
    mario(int X,int Y,QGraphicsItem *parent=0);
    void move(float x,float y);
    float size(){return _size;}
    void setsize(int c);
    void bigger();
    void smaller();
    float gety(){return y;}
    float getx(){return x;}
    ~mario();
signals:
    void sizeChanged(int);
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;

public slots:
   void  start();

};

#endif // MARIO_H
