#include "mygraphicscene.h"
#include"baseobj.h"
#include"info.h"
#include<QString>
#include<QKeyEvent>
#include<QPixmap>
#include<QPainter>
#include<QList>
#include<QDebug>
#include<QMutex>
#include<QString>

MyGraphicScene::MyGraphicScene(int x,QObject *parent)
    :QGraphicsScene(parent),cur_x(x),cur_y(0),x(x)
{
    ov=new GameOver;
    win=0;
    ov->setVisible(false);
    t=0;
    _score=0;
     g=9.80655;
    x1=0,x2=0;
    y1=0,y2=0;
    _Mario=new mario(cur_x+250,380);
    this->addItem(_Mario);

    QString d="score : 0";
    main->showScore(d);
    time=new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(jump()));
    time->setInterval(1);



    _stop=new QTimer(this);
    _stop->setInterval(7);
    connect(_stop,SIGNAL(timeout()),this,SLOT(reduce()));

}

void MyGraphicScene::check()
{
    QMutex *n=new QMutex;
    n->lock();
    BaseObj *base;
    int a[4]={0,0,0,0};
    QList<QGraphicsItem*> list=_Mario->collidingItems(Qt::IntersectsItemBoundingRect);

    if(list.size()==0)
        _Mario->right=1;_Mario->left=1;_Mario->up=1;_Mario->down=1;
    for(int i=0;i<list.size();i++)
    {
        base=dynamic_cast<BaseObj *>(list[i]);
        int e=base->reaction();
        if(e>=0 && e<=3)
        a[e]=1;
    }

    if(finish || _Mario->gety()>450)
    {
        if(time->isActive())
            time->stop();
        if(_stop->isActive())
            _stop->stop();
        finish=1;
           main->close();
           ov->setscore(this->_score);
           qDebug()<<"ov!";
          ov->show();


    }
    if(win)
    {
        if(time->isActive())
            time->stop();
        if(_stop->isActive())
            _stop->stop();
        finish=1;
           main->close();
    }
    if(a[1])_Mario->left=0;
    else {
        _Mario->left=1;
    }
    if(a[2])_Mario->up=0;
    else {_Mario->up=1;}
    if(a[3])_Mario->down=0;
    else {_Mario->down=1;
        if(m)m=0;}
    if(a[0])_Mario->right=0;
    else
    {
        if(!_Mario->right)
        _Mario->right=1;
    }

    if(_Mario->jump==0 && _Mario->down)
    {
        if(time->isActive())
        {
        time->stop();
        x1=x2=y1=y2=0;
        }
        _Mario->Vy=-30;
        _Mario->jump=1;
        _Mario->nu_pic=2;
        update();
        time->start();
    }
    if(x != cur_x)
     {
        cur_x=x;
        setSceneRect(cur_x,0,width(),height());
    }
    else
       update(cur_x,0,width(),height());

    n->unlock();
}

void MyGraphicScene::setscore(int s)
{
    QString m="score : ";
    QString n;
    _score+=s;
    n=QString::number(_score);
    n=m+n;
    main->showScore(n);
}

MyGraphicScene::~MyGraphicScene()
{
    if(time->isActive())
        time->stop();
    if(_stop->isActive())
        _stop->stop();

}

void MyGraphicScene::jump()
{


    if(_Mario->jump)
    {
        if(_Mario->Vx<=5 && _Mario->Vx>=0)
            _Mario->Vx=0;
        if(_Mario->Vx>=-5 && _Mario->Vx<=0)
            _Mario->Vx=0;
        if(_Mario->Vx>=9)
            _Mario->Vx=27;
        if(_Mario->Vx<=-9)
            _Mario->Vx=-27;

        check();
        x1=x2;
        x2=_Mario->Vx*t;

       if((!_Mario->right && _Mario->Vx>0 )||(!_Mario->left && _Mario->Vx<0 ))
       {
           _Mario->jump=0;
            t=0;
            y2=y1=x1=x2=0;
            return;
        }
        else
       {
           _Mario->move(x2-x1,0);
           x+=(x2-x1);
       }
          y1=y2;
          y2=(0.5*(-1)*g* t* t)+(_Mario->Vy )*t;

       if(_Mario->up && (y2-y1)>=0)
       {
           _Mario->move(0,-(y2-y1));
        }
       else if (_Mario->down &&( y2-y1)<0)
        {
           // _Mario->y-=(y2-y1);
           _Mario->move(0,-(y2-y1));
         }
       else
        { 
             _Mario->jump=0;
              t=0;
              y2=y1=x1=x2=0;
              return;
        }
       t+=0.04;
    }
    else
    {
        if(_Mario->down)
            _Mario->move(0,1);
        else
        {
            _Mario->nu_pic=1;
            update();
            time->stop(); check();
            _stop->start();
        }

    }

    check();

}

void MyGraphicScene::reduce()
{
    if(_Mario->Vx>=1)
        _Mario->Vx-=1;
    else if(_Mario->Vx<=-1)
        _Mario->Vx+=1;
    else
    {
        if(_Mario->stop)
        {
            _Mario->time->stop();
            if(!_Mario->jump)
            _Mario->nu_pic=1;
            update();
            _Mario->stop=0;
        }
        _stop->stop();
    }
}

void MyGraphicScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    QPixmap background(":/env/res/airTile.png");
    painter->drawPixmap(QRect(0, 0, width(), height()), background);

}

void MyGraphicScene::keyPressEvent(QKeyEvent *event)
{

    check();
    if(event->key()== Qt::Key_Up)
    {
        _stop->stop();
        if(!_Mario->jump)
        {

            if(_Mario->time->isActive())
            {
            _Mario->time->stop();

            }_Mario->nu_pic=2;
            _Mario->jump=1;
            _Mario->Vy=60;
            time->start();
        }
    }
    if(event->key()==Qt::Key_Right)
    {
        if(_Mario->right)
        {
            _Mario->direct=1;
            if(!_Mario->stop && !_Mario->jump)
            {
                _Mario->time->start();
                _Mario->stop=1;
            }
            if(!_stop->isActive())
            _stop->stop();
        if(_Mario->Vx<=9)
        _Mario->Vx+=5;
        else
            _Mario->Vx=10;

            _Mario->move(_Mario->Vx,0);
            x+=_Mario->Vx;

        }


    }
    if(event->key()==Qt::Key_Left)
    {

        if(_Mario->left)
        {
            _Mario->direct=0;
            if(!_Mario->stop && !_Mario->jump)
            {
                _Mario->time->start();
                _Mario->stop=1;
            }
            if(_stop->isActive())
            _stop->stop();
            if(_Mario->Vx >= -9)
                _Mario->Vx-=5;
            else
                _Mario->Vx=-10;

            _Mario->move(_Mario->Vx,0);
                x+=_Mario->Vx;

        }
    }
    check();
}

void MyGraphicScene::keyReleaseEvent(QKeyEvent *event)
{
    if(!_Mario->jump)
    {
        _stop->start();
    }

}


