#ifndef DRAWLANGUAGEKEYBOARD_H
#define DRAWLANGUAGEKEYBOARD_H
#include"utils/redefineqrect.h"
#include<QPainter>
#include"systemitems.h"
#include<QFont>

class DrawLanguagekeyboard
{
public:
    DrawLanguagekeyboard();
    ~DrawLanguagekeyboard();

    void drawHomeIcon(QPainter *painter,myQRect *rect);
    void drawBackIcon(QPainter *painter,myQRect *rect);
     void drawLanguageTitle(QPainter *painter,myQRect *rect,QString title);
      void drawItems(QPainter *painter,QList<SystemItems*> *itemlist,QString targetlanguage);
private:
      QFont font;

};

#endif // DRAWLANGUAGEKEYBOARD_H
