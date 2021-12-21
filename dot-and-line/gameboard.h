#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include<QPushButton>
#include<QLabel>
#include<QString>
#include"line.h"
#include <QWidget>


class gameboard : public QWidget
{
    Q_OBJECT

    line ***li;
    QPushButton *point;
   QLabel ***lab;

    void set_score();
    void turn();
    void finish();
public:
    explicit gameboard(QWidget *parent = 0);
    ~gameboard();
    void build();
    void check(int ,int);

private:

};

#endif // GAMEBOARD_H

