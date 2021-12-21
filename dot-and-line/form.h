#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include<QScrollArea>
#include"gameboard.h"
#include<QPushButton>
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT
    QScrollArea *scr;
    gameboard *br;

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    
private slots:
    void on_mainmenu_clicked();

    void on_exit_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
