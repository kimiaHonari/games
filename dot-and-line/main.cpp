#include "mainwindow.h"
#include <QApplication>
#include"gameboard.h"
#include"board.h"
#include"form.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    board s;
    s.show();

    
    return a.exec();
}
