#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"form.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Form *b;
private slots:
    void on_player1_textChanged(const QString &arg1);

    void on_player2_textChanged(const QString &arg1);

    void on_row_textChanged(const QString &arg1);

    void on_column_textChanged(const QString &arg1);

    void on_play_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
