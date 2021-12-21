#include "scene.h"
#include<QPainter>
Scene::Scene(QString add, QObject *parent):QGraphicsScene(parent)
{
    _add=add;
}

void Scene::drawBackground(QPainter *painter, const QRectF &rect)
{
    QPixmap background(_add);
    painter->drawPixmap(QRect(0, 0, width(), height()), background);
}
