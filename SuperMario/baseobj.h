#ifndef BASEOBJ_H
#define BASEOBJ_H
#include<QGraphicsObject>
class BaseObj:public QGraphicsObject
{
public:
    float x;float y;
    float width;float height;

    BaseObj(QGraphicsItem *parent=0);
    virtual int reaction()=0;

};

#endif // BASEOBJ_H
