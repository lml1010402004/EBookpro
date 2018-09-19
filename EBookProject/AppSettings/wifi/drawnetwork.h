#ifndef DRAWNETWORK_H
#define DRAWNETWORK_H
#include<QPainter>
#include"utils/redefineqrect.h"
#include"wifiitem.h"
#include<QRect>
#include<QFont>
#include"application/syssettings.h"


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

    void drawCurrentWifiItems(QPainter *painter,QList<wifiItem*> *wifilistitem,int currentPage,int totalPages);

    void drawLastAndNextPage(QPainter *painter,int currentPage,int totalPages,QList<myQRect*> *rectlist);
    QList<wifiItem*> getCurrentPageWifiList(QList<wifiItem*> *list,int currentPage,int totalPages);

private:
        QRect rect;
        SysSettings *mysyssetting;
        QFont font;

};

#endif // DRAWNETWORK_H
