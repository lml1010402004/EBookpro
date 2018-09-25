#ifndef DRAWSWITCHLANGUAGESDIALOG_H
#define DRAWSWITCHLANGUAGESDIALOG_H
#include<QPainter>
#include"utils/redefineqrect.h"
#include<QList>

class DrawSwitchLanguagesDialog
{
public:
    DrawSwitchLanguagesDialog();
    ~DrawSwitchLanguagesDialog();

    void drawLanguagesItems(QPainter *painter,QList<myQRect*> *rectlist, QString items[]);


};

#endif // DRAWSWITCHLANGUAGESDIALOG_H
