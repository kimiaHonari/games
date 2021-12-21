#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QString>
#include"board.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Board *b;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showScore(QString &t);
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
