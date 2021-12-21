#ifndef BOARD_H
#define BOARD_H


#include <QWidget>
#include"mainwindow.h"
#include"about.h"
namespace Ui {
class board;
}

class board : public QWidget
{
    Q_OBJECT

public:
    explicit board(QWidget *parent = 0);
    ~board();
    MainWindow *info;
    about *how;
private slots:
    void on_exitgame_clicked();

    void on_newgame_clicked();

    void on_howtoplay_clicked();



private:
    Ui::board *ui;
};

#endif // BOARD_H
