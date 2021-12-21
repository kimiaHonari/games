#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include"mygraphicscene.h"
#include<QFile>
namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT
    QFile *file;
    QGraphicsView *view;
public:

    explicit Board(QWidget *parent = 0);
    ~Board();
    void build();

private:
    Ui::Board *ui;
};

#endif // BOARD_H
