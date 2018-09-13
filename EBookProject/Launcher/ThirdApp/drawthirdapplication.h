#ifndef DRAWTHIRDAPPLICATION_H
#define DRAWTHIRDAPPLICATION_H
#include"Utils/redefineqrect.h"
#include<QPainter>
#include"DataItem/systemitems.h"
#include<QFont>


class DrawThirdApplication
{
public:
    DrawThirdApplication();
    ~DrawThirdApplication();

    void drawHomeIcon(QPainter *painter,myQRect *rect);
    void drawAppsText(QPainter *painter,QString text,myQRect *rect);
    void drawAppsItems(QPainter *painter,QList<SystemItems*> *itemlist);
    QFont font;
};

#endif // DRAWTHIRDAPPLICATION_H
