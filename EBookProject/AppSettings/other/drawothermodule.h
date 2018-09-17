#ifndef DRAWOTHERMODULE_H
#define DRAWOTHERMODULE_H
#include"utils/redefineqrect.h"
#include<QPainter>
#include"dataitem/systemitems.h"
#include<QFont>

class DrawOtherModule
{
public:
    DrawOtherModule();
    ~DrawOtherModule();

    void drawHomeIcon(QPainter *painter,myQRect *rect);
    void drawBackIcon(QPainter *painter,myQRect *rect);
    void drawTitle(QPainter *painter,myQRect *rect,QString title);
    void drawOtherSettingItems(QPainter *painter,QList<SystemItems*> *itemlist);

private:
    QFont font;


};

#endif // DRAWOTHERMODULE_H
