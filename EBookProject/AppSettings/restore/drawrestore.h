#ifndef DRAWRESTORE_H
#define DRAWRESTORE_H
#include<QPainter>
#include<utils/redefineqrect.h>



class DrawRestore
{
public:
    DrawRestore();
    ~DrawRestore();
    void drawTitle(QPainter *painter,myQRect *rect,QString title);
    void drawBackIcon(QPainter *painter,myQRect *rect);
    void drawHomeIcon(QPainter *painter,myQRect *rect);
    void drawConfirmButton(QPainter *painter,myQRect *rect,QString str);

};

#endif // DRAWRESTORE_H
