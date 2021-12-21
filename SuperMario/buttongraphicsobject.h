#ifndef BUTTONGRAPHICSOBJECT_H
#define BUTTONGRAPHICSOBJECT_H

#include <QGraphicsObject>
#include<QBrush>
class ButtonGraphicsObject : public QGraphicsObject
{
    Q_OBJECT
    int width,height;
    int x,y;
    QString _add;

public:
    explicit ButtonGraphicsObject(int width,int height,QString add,QGraphicsItem *parent = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;

signals:
    void clicked();
public slots:
protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // BUTTONGRAPHICSOBJECT_H
