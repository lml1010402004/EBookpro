#ifndef DRAWNETWORK_H
#define DRAWNETWORK_H
#include<QPainter>
#include"utils/redefineqrect.h"


class DrawNetwork
{
public:
    DrawNetwork();
    ~DrawNetwork();

    void drawHomeIcon(QPainter *painter,myQRect *rect);
    void drawBackIcon(QPainter *painter,myQRect *rect);
    void drawNetworkTitle(QPainter *painter,myQRect *rect,QString title);
    void drawNetworkWifiText(QPainter *painter,myQRect *rect,QString title);
    void drawNetworkSwitch(QPainter *painter,myQRect *rect);
    void drawSearchResultTitle(QPainter *painter, myQRect *rect,QString title);
    void drawSwitchButton(QPainter *painter,QRect switchbutton,bool checked);




};

#endif // DRAWNETWORK_H
