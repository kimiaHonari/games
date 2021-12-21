#ifndef GAMEOVER_H
#define GAMEOVER_H
#include<QWidget>
#include"scene.h"
class Form;
class GameOver:public QWidget
{
    Q_OBJECT
    int score;
   Form *f;
   Scene *scene;
public:
    GameOver(QWidget *parent=0);
    void setscore(int s);
public slots:
    void start();
    void exit();
};

#endif // GAMEOVER_H
