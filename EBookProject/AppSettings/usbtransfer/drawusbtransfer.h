#ifndef DRAWUSBTRANSFER_H
#define DRAWUSBTRANSFER_H
#include"utils/redefineqrect.h"
#include<QPainter>

class DrawUsbtransfer
{
public:
    DrawUsbtransfer();
    ~DrawUsbtransfer();

    void drawHomeIcon(QPainter *painter,myQRect *rect);
    void drawBackIcon(QPainter *painter,myQRect *rect);
    void drawTitle(QPainter *painter,myQRect *rect,QString title);
    void drawLogo(QPainter *painter,myQRect *rect);
    void drawState(QPainter *painter,myQRect *rect,QString title);
    void drawDataTransferOrChargeOnly(QPainter *painter,myQRect *rect,QString str);

};

#endif // DRAWUSBTRANSFER_H
