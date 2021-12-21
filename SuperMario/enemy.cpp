#include "enemy.h"
#include<QPainter>
#include<QMutex>
#include"info.h"
#include<QDebug>
Enemy::Enemy(float X,float Y,QGraphicsItem *parent)
    :BaseObj(parent)
{
    x=X;y=Y;
    width=height=60;
    _dir=0;
    death=0;
    rec=new QRect(x,y,width,height);
    _counter=0;
    time1=new QTimer(this);
    connect(time1,SIGNAL(timeout()),this,SLOT(start()));
    time1->setInterval(3000);
    time1->start();
   time2=new QTimer(this);
    connect(time2,SIGNAL(timeout()),this,SLOT(change()));
    time2->setInterval(1000);
    time2->start();
    t=new QTimer(this);
     connect(t,SIGNAL(timeout()),this,SLOT(disapear()));
     t->setInterval(300);


}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QMutex m;
    m.lock();

    QPixmap* background;
    if(!death)
    {
       rec->moveTo(x,y);
       int b=_counter+1;
       QString add(":/enemy/res/enemy/goomba/");
       add.append(QString::number(b));
       add.append(".png");
       background=new QPixmap(add);
    }
    else
    {
       background=new QPixmap(":/enemy/res/enemy/goomba/Death1.png");
    }
    painter->drawPixmap(x,y,width,height,*background);

    m.unlock();
}

QRectF Enemy::boundingRect() const
{
     return QRectF(x,y,width,height);
}

int Enemy::reaction()
{
    if(_scene->_Mario->rec->bottom() <= rec->top())
    {
        if(!death)
        {
            death=1;

            if(_dir)
                right->stop();
            else
                left->stop();
            if(time1->isActive())
           time1->stop();
            if(time2->isActive())
            time2->stop();
            if(_scene->time->isActive())
            {
            _scene->time->stop();
            _scene->x1=_scene->x2=_scene->y1=_scene->y2=_scene->t=0;
            }
            if(_scene->_Mario->time->isActive())
                _scene->_Mario->time->stop();
            _scene->_Mario->jump=1;
            _scene->_Mario->Vy=50;
            if(_scene->_Mario->direct)
                _scene->_Mario->Vx=7;
            else
                _scene->_Mario->Vx=-7;
            _scene->_Mario->nu_pic=2;
            //_scene->update();
            _scene->time->start();
            t->start();
            _scene->setscore(500);
        }
    }
    else
    {
        qDebug()<<"finish";
        if(!_scene->_Mario->big)
           finish=1;
        else
        {
            _scene->_Mario->smaller();
            _scene->setscore(-300);
           // t->start();
        }
    }
    return 4;
}

void Enemy::setcounter(int c)
{
    if(c==_counter )
        return;
    _counter=c;
    emit counterChanged(c);
    update();
}

void Enemy::setmove(float c)
{
    if(c==x)return;
    if(finish )
    {
        if(time1->isActive())
       time1->stop();
        if(time2->isActive())
        time2->stop();
    }
    else
    {
    x=c;

    if(this->collidesWithItem(_scene->_Mario) )
    {

           finish=1;

        _scene->check();
    }
   emit  moveChanged(c);
    update();

    }
}


void Enemy::change()
{
    if(!_dir)
    {

        anim=new QPropertyAnimation(this,"counter");
        anim->setStartValue(3);
        anim->setEndValue(6);
        anim->setDuration(1000);
        anim->start(QAbstractAnimation::DeleteWhenStopped);

    }
    else
    {
        anim=new QPropertyAnimation(this,"counter");
        anim->setStartValue(0);
        anim->setEndValue(3);
        anim->setDuration(1000);
        anim->start(QAbstractAnimation::DeleteWhenStopped);

    }
}

void Enemy::start()
{

    if(!_dir)
    {
        right=new QPropertyAnimation(this,"move");
        right->setStartValue(x);
        right->setEndValue(x+220);
        right->setDuration(3000);
        right->start(QAbstractAnimation::DeleteWhenStopped);
        _dir=1;

    }
    else
    {
        left=new QPropertyAnimation(this,"move");
        left->setStartValue(x);
        left->setEndValue(x-220);
        left->setDuration(3000);
       left->start(QAbstractAnimation::DeleteWhenStopped);
       _dir=0;

    }

}

void Enemy::disapear()
{
    this->hide();
    t->stop();
    if(time1->isActive())
   time1->stop();
    if(time2->isActive())
    time2->stop();
    delete time1;
    delete time2;
    delete t;
    delete rec;
}



