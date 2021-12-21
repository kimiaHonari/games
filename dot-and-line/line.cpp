#include "line.h"
#include<QObject>
#include"gameboard.h"
#include"information.h"
line::line(int i,int j,QWidget *parent):QPushButton(parent)
{
    this->i=i;this->j=j;
   QObject:: connect(this,SIGNAL(clicked()),this,SLOT(showed()));
  // this->setStyleSheet("*{background-color:rgba(180,180,180,0.5);}");
   pa=parent;
}

void line::showed()
{
    if(state==_show)
        return;
   // changecolor(changeuser);
    state=_show;
    this->setStyleSheet("*{background-color:"+color+";}");
    gameboard *b=dynamic_cast<gameboard *>(pa);
    b->check(i,j);

}
bool line::isshow()
{
    if(state==_show)
        return true;
    return false;
}


