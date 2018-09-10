#ifndef DRAWMAINWINDOW_H
#define DRAWMAINWINDOW_H
#include<QPainter>
#include<QPaintEvent>
#include"utils/redefineqrect.h"
#include<QFont>
#include"dataitem/systemitems.h"


class DrawMainWindow
{
public:
    DrawMainWindow();
    ~DrawMainWindow();

    void drawHomeIcon(QPainter *painter,myQRect *rect);
    void drawSystemSettingText(QPainter *painter,QString text,myQRect *rect);
    void drawSettingItems(QPainter *painter,QList<SystemItems*> *itemlist);


private:
    QFont font;
};

#endif // DRAWMAINWINDOW_H
