#include "about.h"
#include "ui_about.h"
#include"information.h"
about::about(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);

    this->setFixedSize(560,692);
    QImage image(":/back/res/how.jpg");
    QPalette palette;
     palette.setBrush(this->backgroundRole(), QBrush(image));
     this->setPalette(palette);
}

about::~about()
{

    delete ui;
}

void about::on_point_clicked()
{

    this->close();
    add->show();
}
