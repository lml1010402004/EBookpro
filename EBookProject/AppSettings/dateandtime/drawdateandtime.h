#ifndef DRAWDATEANDTIME_H
#define DRAWDATEANDTIME_H
#include<QPainter>
#include<utils/redefineqrect.h>
#include"dataitem/datemodel.h"
#include"systemitems.h"
#include<QFont>


class DrawDateAndTime
{
public:
    DrawDateAndTime();
    ~DrawDateAndTime();
    void drawHomeIcon(QPainter *painter,myQRect *rect);
    void drawBackIcon(QPainter *painter,myQRect *rect);
    void drawTitle(QPainter *painter,myQRect *rect,QString title);
    void drawDateAndTimeItems(QPainter *painter,QList<SystemItems*> *itemlist,dateModel *date);

private:
    QFont font;
};

#endif // DRAWDATEANDTIME_H
