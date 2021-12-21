#include "reward.h"

Reward::Reward(float X, float Y, QGraphicsItem *parent):BaseObj(parent)
{
    x=X;y=Y;
    _counter=0;
}

int Reward::reaction()
{
    score();
    return 4;
}
