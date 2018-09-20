#ifndef DRAWCONNECTWIFIDIALOG_H
#define DRAWCONNECTWIFIDIALOG_H
#include<QPainter>
#include"utils/redefineqrect.h"
#include<QFont>


class DrawConnectWifiDialog
{
public:
    DrawConnectWifiDialog();
    ~DrawConnectWifiDialog();

    void drawTargetWifiTitle(QPainter *painter,myQRect *rect,QString title);
    void drawDialogRect(QPainter *painter,myQRect rect);
    void drawWifiText(QPainter *painter,myQRect *rect,QString str);
    void drawConnOrCancleButton(QPainter *painter,myQRect *rect,QString str);
   private:
    QFont font;

};

#endif // DRAWCONNECTWIFIDIALOG_H
