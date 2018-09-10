#ifndef DRAWWALLPAPER_H
#define DRAWWALLPAPER_H
#include<QPaintEvent>
#include<QPainter>
#include<QLineF>
#include<QRect>
#include"dataitem/systemitems.h"
#include"utils/redefineqrect.h"

class DrawWallpaper
{
public:
    DrawWallpaper();
    ~DrawWallpaper();

    void drawHomeIcon(QPainter *paitner,myQRect rect);
    void drawBackIcon(QPainter *painter,myQRect rect);
    void drawWallPapaerItem(QPainter *painter,int index);

private:
    QLineF line;
    QRect rect;



};

#endif // DRAWWALLPAPER_H
