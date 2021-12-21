#ifndef WINGAME_H
#define WINGAME_H
#include<QWidget>
#include"scene.h"
class Form;
class WinGame:public QWidget
{
    Q_OBJECT
    int score;
    Form *f;
    Scene *scene;
public:
    WinGame(QWidget *parent=0);
    void setscore(int s);
public slots:
    void start();
    void exit();
};

#endif // WINGAME_H
