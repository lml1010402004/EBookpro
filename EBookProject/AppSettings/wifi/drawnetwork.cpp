#include "drawnetwork.h"
#include"utils/application.h"

extern const QString home_pressed;
extern const QString home_unpress;
extern const QString back_unpress;
extern const QString back_pressed;
extern const QString wifi_open;
extern const QString wifi_closed;



DrawNetwork::DrawNetwork()
{

}

DrawNetwork::~DrawNetwork()
{

}

void DrawNetwork::drawHomeIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,home_pressed);
    }else{
        painter->drawPixmap(rect->rect,home_unpress);
    }
}

void DrawNetwork::drawBackIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,back_pressed);
    }else{
        painter->drawPixmap(rect->rect,back_unpress);
    }
}

void DrawNetwork::drawNetworkTitle(QPainter *painter, myQRect *rect, QString title)
{
    painter->drawText(rect->rect,title);
}

void DrawNetwork::drawNetworkWifiText(QPainter *painter, myQRect *rect, QString title)
{
    painter->drawText(rect->rect,title);
}

void DrawNetwork::drawNetworkSwitch(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,wifi_open);
    }else{
        painter->drawPixmap(rect->rect,wifi_closed);
    }
}

void DrawNetwork::drawSearchResultTitle(QPainter *painter, myQRect *rect,QString title)
{
    painter->drawText(rect->rect,title);
}

void DrawNetwork::drawSwitchButton(QPainter *painter, QRect switchbutton, bool checked)
{
    if(checked){
        painter->drawPixmap(switchbutton,wifi_open);
    }else{
        painter->drawPixmap(switchbutton,wifi_closed);
    }
}
