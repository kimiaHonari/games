#ifndef INFORMATION_H
#define INFORMATION_H
#include<QString>
#include<QPushButton>
#include<QLabel>
#include"board.h"
extern QString name1,name2,color1,color2;
//="*{back-ground:rgb(245,11,11);}",="*{back-ground:rgb(20,31,225);}";
extern int rows;
extern int columns;
extern bool changeuser;
extern QString color;
void changecolor(bool a);
extern int count_square;
extern QString score_1,score_2;
extern QPushButton *set_turn;
extern QLabel *score1,*score2;
extern board *add;

#endif // INFORMATION_H
