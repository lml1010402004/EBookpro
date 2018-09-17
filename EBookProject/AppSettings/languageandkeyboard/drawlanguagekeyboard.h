#ifndef DRAWLANGUAGEKEYBOARD_H
#define DRAWLANGUAGEKEYBOARD_H
#include"utils/redefineqrect.h"
#include<QPainter>

class DrawLanguagekeyboard
{
public:
    DrawLanguagekeyboard();
    ~DrawLanguagekeyboard();

    void drawHomeIcon(QPainter *painter,myQRect *rect);
    void drawBackIcon(QPainter *painter,myQRect *rect);
     void drawLanguageTitle(QPainter *painter,myQRect *rect,QString title);

};

#endif // DRAWLANGUAGEKEYBOARD_H
