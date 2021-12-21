#ifndef LINE_H
#define LINE_H
#include<QPushButton>
#include<QString>

enum condition{_unshow=0,_show=1};
class line:public QPushButton
{
    condition state;
    int i,j;
    QWidget *pa;
    Q_OBJECT
public:
    line(int i,int j,QWidget *parent=0);
 signals:

 public slots:
    void showed();
    bool isshow();
};

#endif // LINE_H


