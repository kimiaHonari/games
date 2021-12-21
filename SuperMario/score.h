#ifndef SCORE_H
#define SCORE_H
#include<QGraphicsItem>
#include<QString>
class Score: public QGraphicsItem
{
    float x,y;
    QString s;
public:
    Score(QString s, float x, float y, QGraphicsItem *parent=0);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect()const;
};

#endif // SCORE_H
