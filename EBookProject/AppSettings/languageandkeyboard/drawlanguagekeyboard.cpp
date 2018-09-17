#include "drawlanguagekeyboard.h"
#include "utils/application.h"
extern const QString home_pressed;
extern const QString home_unpress;
extern const QString back_unpress;
extern const QString back_pressed;



DrawLanguagekeyboard::DrawLanguagekeyboard()
{

}

DrawLanguagekeyboard::~DrawLanguagekeyboard()
{

}

void DrawLanguagekeyboard::drawHomeIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,home_pressed);
    }else{
        painter->drawPixmap(rect->rect,home_unpress);
    }
}

void DrawLanguagekeyboard::drawBackIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,back_pressed);
    }else{
        painter->drawPixmap(rect->rect,back_unpress);
    }

}

void DrawLanguagekeyboard::drawLanguageTitle(QPainter *painter, myQRect *rect, QString title)
{
 painter->drawText(rect->rect,title);
}
