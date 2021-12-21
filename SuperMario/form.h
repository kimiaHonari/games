#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include"mainwindow.h"
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT
    MainWindow *b;
public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    void again();
public slots:
    void start();
    void exit();
private:
    Ui::Form *ui;
};

#endif // FORM_H
