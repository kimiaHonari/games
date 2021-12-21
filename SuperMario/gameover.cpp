#include "gameover.h"

#include"buttongraphicsobject.h"
#include<QGraphicsView>
#include"info.h"
#include"form.h"
#include"score.h"
GameOver::GameOver(QWidget *parent):
QWidget(parent)
{

    setFixedSize(800,650);
    QGraphicsView *view=new QGraphicsView(this);
    view->setGeometry(0,0,802,657);
    QString add=":/background/res/gameover.jpg";
    scene=new Scene(add);
    scene->setSceneRect(0,0,800,652);
    view->setScene(scene);

    ButtonGraphicsObject *btn_start=new ButtonGraphicsObject(200,52,":/button/res/button/new game.jpg");
    scene->addItem(btn_start);
    btn_start->setPos(100,350);

    ButtonGraphicsObject *btn_exit=new ButtonGraphicsObject(200,50,":/button/res/button/exit.jpg");
    scene->addItem(btn_exit);
    btn_exit->setPos(100,420);
    connect(btn_start,SIGNAL(clicked()),this,SLOT(start()));
    connect(btn_exit,SIGNAL(clicked()),this,SLOT(exit()));
}

void GameOver::setscore(int s)
{
    score=s;
    QString st;
    st=QString::number(s);
    Score *f=new Score(st,590,520);
    scene->addItem(f);
}

void GameOver::start()
{
   finish=0;
    this->close();
    main->close();
    f=new Form();
    delete main;
    f->again();

}
void GameOver::exit()
{
    this->close();
    main->close();

}
