
#include <QApplication>
#include"mainwindow.h"
#include"form.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

  Form y;
 y.show();

    return a.exec();
}
