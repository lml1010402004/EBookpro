#ifndef DRAWPULLDOWNWINDOW_H
#define DRAWPULLDOWNWINDOW_H
#include<QList>
#include<QRect>
#include<QPainter>
#include<QString>

const QString wifi_unpress=":/pic/pic/wifi.png";
const QString wifi_press=":/pic/pic/wifi_pressed.png";
const QString setting_unpress=":/pic/pic/setting_unpress.png";
const QString setting_press=":/pic/pic/setting_pressed.png";
const QString search_unpress=":/pic/pic/search_unpress.png";
const QString search_press=":/pic/pic/search_pressed.png";

const QString minus_unpress=":/pic/pic/minus_uppress.png";
const QString minus_press=":/pic/pic/minus_pressed.png";
const QString plus_unpress=":/pic/pic/plus_unpress.png";
const QString plus_press=":/pic/pic/plus_pressed.png";

const QString closeIcon =":/pic/pic/pulldown_close.png";

class DrawPulldownWindow
{
public:
    DrawPulldownWindow();
    ~DrawPulldownWindow();

   void drawCloseIcon(QPainter *painter,QRect rect);
   void drawShortcutArea(QPainter *painter,QRect rect);
   void drawGrayArea(QPainter *painter,int al,QRect rect);
   void drawShortcutIcons(QPainter *painter,int pressed1,QRect rect1,int pressed2,QRect rect2,int pressed3,QRect rect3);
   void drawLightshortcutandProgressBar(QPainter *painter,QString lightpath,int light_volume,QRect rect,QString floatpath);


   void drawLightPlus(QPainter *painter,QRect plusrect,int pressed);
   void drawLightMinus(QPainter *painter,QRect minusrect,int pressed);

};

#endif // DRAWPULLDOWNWINDOW_H
