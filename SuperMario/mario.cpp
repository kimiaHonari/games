#include "mario.h"
#include<QPainter>

mario::mario(int X, int Y, QGraphicsItem *parent):QGraphicsObject(parent)
  ,x(X),y(Y),counter(0),Vx(0),Vy(0)
{
    big=0;
    _size=1;
    width=height=30;
    jump=0;
    rec=new QRect(x,y,width,height);
    nu_pic=1;
    direct=1;
    time=new QTimer(this);
    time->setInterval(250);
    connect(time,SIGNAL(timeout()),this,SLOT(start()));
    stop=0;
setZValue(1.1);

}

void mario::move(float x, float y)
{
    this->x+=x;
    this->y+=y;
}

void mario::setsize(int c)
{
    if(c==_size)
    {
        return;
    }
    width+=(c-_size);
    height+=(c-_size);
     y-=(c-_size);
     rec->setHeight(height);
     rec->setWidth(width);
    _size=c;

    emit sizeChanged(c);
    update();
}

void mario::bigger()
{

    anim=new QPropertyAnimation(this,"size");
    anim->setStartValue(_size);
    anim->setEndValue(_size+13);
    anim->setDuration(1000);
   // anim->setEasingCurve(QEasingCurve::OutElastic);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
    big=1;
}

void mario::smaller()
{
    anim=new QPropertyAnimation(this,"size");
    anim->setStartValue(_size);
    anim->setEndValue(1);
    anim->setDuration(1000);
   // anim->setEasingCurve(QEasingCurve::OutElastic);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
    big=0;
}

mario::~mario()
{
    if(time->isActive())
        time->stop();


}


void mario::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    rec->moveTo(x,y);
    QPixmap* background;
    if(nu_pic==0)
    {
        if(direct)
        background=new QPixmap(":/mario_right/res/walk.png");
        else
          background=new QPixmap(":/mario_left/res/walk_left.png");
        painter->drawPixmap(x,y,width,height,*background);
    }
    if(nu_pic==1)
    {
        if(direct)
            background=new QPixmap(":/mario_right/res/still.png");
        else
           background=new QPixmap(":/mario_left/res/still_left.png");
        painter->drawPixmap(x,y,width,height,*background);
    }
    if(nu_pic==2)
    {
        if(direct)
            background=new QPixmap(":/mario_right/res/jump.png");
        else
           background=new QPixmap(":/mario_left/res/jump_left.png");
        painter->drawPixmap(x,y,width,height,*background);
    }
}

QRectF mario::boundingRect() const
{
    return QRectF(x,y,width+7,height+3);
}


void mario::start()
{
    static int i=0;
    nu_pic=i;
    if(i)i=0;
    else
        i=1;
    update();

}
