#ifndef DRAWBOOKSHELF_H
#define DRAWBOOKSHELF_H
#include<QPainter>
#include<QString>
#include"DataItem/conditionitem.h"
#include"DataBase/database.h"
#include<QRect>

class DrawBookshelf
{
public:
    DrawBookshelf();
    ~DrawBookshelf();
    void drawHomeButton(QPainter *painter,QRect rect,int flag);
    void drawArrangeTextView(QPainter *painter,QRect rect,QString str);
    void drawSelectedCondition(QPainter *painter,QList<ConditionItem> *conditionlist,int index);
    void drawNineBooks(QPainter *painter,QList<localDirectoryItem> *booklist);

    void drawTheFirstandLastPageIcon(QPainter *painter,QRect firstrect,int firstflag,QRect lastrect,int lastflag);
    void drawTheNextandEndPageIcon(QPainter *painter,QRect nextrect,int nextflag,QRect endrect,int endflag);
    void drawCurrentPageandTotalPages(QPainter *painter,int currentpage,int totalpages,QRect rect);
    QRect rect;

};

#endif // DRAWBOOKSHELF_H
