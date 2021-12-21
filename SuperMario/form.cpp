#include "form.h"
#include "ui_form.h"
#include"buttongraphicsobject.h"
#include<QGraphicsScene>
#include"scene.h"
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setFixedSize(800,650);

    QString add=":/background/res/back1.jpg";
    Scene *scene=new Scene(add);
    scene->setSceneRect(0,0,800,650);
    ui->view->setScene(scene);
    ButtonGraphicsObject *btn_start=new ButtonGraphicsObject(200,52,":/button/res/button/new game.jpg");
    scene->addItem(btn_start);
    btn_start->setPos(500,300);

    ButtonGraphicsObject *btn_exit=new ButtonGraphicsObject(200,50,":/button/res/button/exit.jpg");
    scene->addItem(btn_exit);
    btn_exit->setPos(500,370);
    connect(btn_start,SIGNAL(clicked()),this,SLOT(start()));
    connect(btn_exit,SIGNAL(clicked()),this,SLOT(exit()));
}

Form::~Form()
{
    delete ui;
}

void Form::again()
{
    b=new MainWindow;
    b->show();
}


void Form::start()
{
    b=new MainWindow;
    b->show();
    this->close();
}

void Form::exit()
{
    this->close();
}
