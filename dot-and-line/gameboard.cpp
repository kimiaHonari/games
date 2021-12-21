#include "gameboard.h"
#include"information.h"
#include<QMessageBox>
#include<QPalette>
gameboard::gameboard(QWidget *parent) :
    QWidget(parent)
{
   QImage image(":/back/res/gameboard.jpg");
   QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(image));
    this->setPalette(palette);


    this->setFixedSize((30+(columns*10)+(columns-1)*30),(45+(rows*10)+(rows-1)*30));
    li=new line**[(2*rows)-1];
    lab=new QLabel**[rows-1];
    int y=0;
    for(int i=0;i<(2*rows-1);i++)
    {
        if(i%2==0)
        {
            li[i]=new line*[columns-1];
        }
        else
        {
            li[i]=new line*[columns];
            lab[y]=new QLabel*[columns-1];
            y++;
        }
    }
}
void gameboard::build()
{
    int z=0;
  int x1=0,x2=0,y=35;
 for(int i=0;i<((2*rows)-1);i++)
  {
       if(i%2==0)
       {
           x1=20;
           x2=30;
           for(int j=0;j<columns;j++)
          {
           point=new QPushButton(this);
           point->setStyleSheet("*{background-color:rgb(7,10,170);}");
           point->setGeometry(x1,y,10,10);
           if(j!=columns-1)
           {
               li[i][j]=new line(i,j,this);
               li[i][j]->setGeometry(x2,y+2.5,30,5);
           }

          x1+=40;
          x2+=40;
           }
           y+=10;
       }
       else
       {
           x1=22.5;
           x2=30;
           for(int j=0;j<columns;j++)
           {
               li[i][j]=new line(i,j,this);
               li[i][j]->setGeometry(x1,y,5,30);
               if(j!=columns-1&& z!=rows-1)
               {
                   lab[z][j]=new QLabel(this);
                   //lab[z][j]->setFlat(true);
                   lab[z][j]->setGeometry(x2,y,30,30);
               }
               x1+=40;
               x2+=40;
           }
               z++;y+=30;
       }


  }
}

void gameboard::check(int i,int j)
{
    bool flag=0;
    if(i%2==0)
    {
        if((i-1)>=0)
        {
            if(li[i-1][j]->isshow() && li[i-1][j+1]->isshow() && li[i-2][j]->isshow())
            {
                    lab[(i/2)-1][j]->setStyleSheet("*{background-color:"+color+";}");
                    set_score();

                flag=1;
            }

        }
        if((i+1)<(2*rows-1))
        {
            if(li[i+1][j]->isshow() && li[i+1][j+1]->isshow() && li[i+2][j]->isshow())
            {

                    lab[(i/2)][j]->setStyleSheet("*{background-color:"+color+";}");
                      set_score();
                     flag=1;
            }
        }

    }
    else
    {
        if((j-1)>=0)
        {
            if(li[i][j-1]->isshow() && li[i-1][j-1]->isshow() && li[i+1][j-1]->isshow())
            {

                lab[(i/2)][j-1]->setStyleSheet("*{background-color:"+color+";}");
                set_score();
                flag=1;
            }
        }
        if(j+1<columns)
        {
            if(li[i][j+1]->isshow() && li[i-1][j]->isshow() && li[i+1][j]->isshow())
            {

               lab[(i/2)][j]->setStyleSheet("*{background-color:"+color+";}");
               set_score();
                flag=1;
            }
        }

    }
    if(!flag)
    {
        if(changeuser)
            changeuser=0;
        else
            changeuser=1;
        changecolor(changeuser);
        turn();
    }
    if(!count_square)
    {
        finish();
    }
}

void gameboard::set_score()
{
    count_square--;
    if(changeuser)
    {
        int x=score1->text().toInt();
        x++;
        score_1=QString::number(x);
        score1->setText(score_1);
    }
    else
    {
        int x=score2->text().toInt();
        x++;
        score_2=QString::number(x);
        score2->setText(score_2);
    }
}

void gameboard::turn()
{
    set_turn->setStyleSheet("*{background-color:"+color+";}");
}

void gameboard::finish()
{
    if(score1->text().toInt() > score2->text().toInt())
        QMessageBox::information(0,"WINNER",name1+" with "+score_1+" score!");
    if(score1->text().toInt() < score2->text().toInt())
        QMessageBox::information(0,"WINNER",name2+" with "+score_2+" score!");
    if(score1->text().toInt() == score2->text().toInt())
        QMessageBox::information(0,"WINNER",name1+" with "+score_1 +" score!\n"+name2+" with "+score_2+" score!");

}

gameboard::~gameboard()
{
    delete point;
    for(int i=0;i<(rows)-1;i++)
        delete []lab[i];
    for(int i=0;i<(2*rows)-1;i++)
        delete []li[i];
}
