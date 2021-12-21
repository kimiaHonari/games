#ifndef MYGRAPHICSCENE_H
#define MYGRAPHICSCENE_H
#include"mario.h"
#include <QObject>
#include<QGraphicsScene>
#include<QLabel>
#include <QTimer>
#include"gameover.h"

class MyGraphicScene : public QGraphicsScene
{
    Q_OBJECT

    GameOver *ov;
public:
    bool win;
    int _score;
     float t;
    float g;
    float x1,x2;
    float y1,y2;
    QTimer *time,*_stop;
    mario *_Mario;
    float cur_x,cur_y;
    float x;
    MyGraphicScene(int x, QObject *parent=0);
    void check();
    void setscore(int s);
    ~MyGraphicScene();
public slots:
    void jump();
    void reduce();
private:
    void drawBackground(QPainter *painter, const QRectF &rect);
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // MYGRAPHICSCENE_H
