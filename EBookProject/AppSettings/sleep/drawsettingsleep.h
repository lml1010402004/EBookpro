#ifndef DRAWSETTINGSLEEP_H
#define DRAWSETTINGSLEEP_H
#include"utils/redefineqrect.h"
#include<QPainter>
#include<QRect>
#include<QLineF>

class drawSettingSleep
{
public:
    drawSettingSleep();
    ~drawSettingSleep();

    void drawBackIcon(QPainter *painter,myQRect *rect);
    void drawHomeIcon(QPainter *painter,myQRect *rect);
    void drawTitle(QPainter *painter,myQRect *rect,QString title);

    void drawSleepTimeListview(QPainter *painter,int targetindex);



};

#endif // DRAWSETTINGSLEEP_H
