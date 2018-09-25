#ifndef DRAWSETTIMEDIALOG_H
#define DRAWSETTIMEDIALOG_H
#include"utils/redefineqrect.h"
#include<QPainter>

class DrawSettimeDialog
{
public:
    DrawSettimeDialog();
    ~DrawSettimeDialog();

    void drawSettimeDialogTitle(QPainter *painter,myQRect *rect,QString title);
    void drawYesAndNoButtons(QPainter *painter,myQRect *yes,QString yesstr,myQRect *no,QString nostr);

};

#endif // DRAWSETTIMEDIALOG_H
