#ifndef DRAWBOOKSHELF_H
#define DRAWBOOKSHELF_H
#include<QPainter>
#include<QString>
#include"DataItem/conditionitem.h"
#include"DataBase/database.h"
#include"Utils/redefineqrect.h"
#include<QRect>

class DrawBookshelf
{
public:
    DrawBookshelf();
    ~DrawBookshelf();
    void drawHomeButton(QPainter *painter,myQRect *rect);
    void drawArrangeTextView(QPainter *painter,myQRect *rect,QString str);
    void drawSelectedCondition(QPainter *painter,QList<ConditionItem> *conditionlist,int index);
    void drawNineBooks(QPainter *painter,QList<localDirectoryItem> *booklist);

    void drawTheFirstandLastPageIcon(QPainter *painter,myQRect *firstrect,myQRect *lastrect);
    void drawTheNextandEndPageIcon(QPainter *painter,myQRect *nextrect,myQRect *endrect);
    void drawCurrentPageandTotalPages(QPainter *painter,int currentpage,int totalpages,myQRect *rect);
    QRect rect;

};

#endif // DRAWBOOKSHELF_H
