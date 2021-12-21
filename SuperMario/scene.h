#ifndef SCENE_H
#define SCENE_H
#include<QGraphicsScene>
#include<QString>
class Scene:public QGraphicsScene
{
    QString _add;
public:
    Scene(QString add,QObject *parent=0);
private:
    void drawBackground(QPainter *painter, const QRectF &rect);
};

#endif // SCENE_H
