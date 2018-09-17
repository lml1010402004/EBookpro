#ifndef DRAWBRIGHTNESS_H
#define DRAWBRIGHTNESS_H
#include<QPainter>
#include"utils/redefineqrect.h"

class DrawBrightness
{
public:
    DrawBrightness();
    ~DrawBrightness();

    void drawBackIcon(QPainter *painter,myQRect *rect);
    void drawHomeIcon(QPainter *painter,myQRect *rect);
    void drawTitle(QPainter *painter,myQRect *rect,QString title);
    void drawMinusButton(QPainter *painter,myQRect *rect);
    void drawPlusButton(QPainter *painter,myQRect *rect);
};

#endif // DRAWBRIGHTNESS_H
