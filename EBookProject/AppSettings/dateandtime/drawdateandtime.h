#ifndef DRAWDATEANDTIME_H
#define DRAWDATEANDTIME_H
#include<QPainter>
#include<utils/redefineqrect.h>
#include"dataitem/datemodel.h"


class DrawDateAndTime
{
public:
    DrawDateAndTime();
    ~DrawDateAndTime();
    void drawHomeIcon(QPainter *painter,myQRect *rect);
    void drawBackIcon(QPainter *painter,myQRect *rect);
    void drawTitle(QPainter *painter,myQRect *rect,QString title);
    void drawDateAndTimeItems(QPainter *painter,dateModel *date);
};

#endif // DRAWDATEANDTIME_H
