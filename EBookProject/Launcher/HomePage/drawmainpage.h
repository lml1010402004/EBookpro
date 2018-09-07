#ifndef DRAWMAINPAGE_H
#define DRAWMAINPAGE_H

#include<QPainter>
#include<QString>
#include<QStringList>
#include<QList>
#include<QFont>
#include"DataBase/database.h"
#include"Utils/redefineqrect.h"




class DrawMainPage
{
public:
    DrawMainPage();
    ~DrawMainPage();

    QFont font;


    void drawCurrentBookCover(QPainter *painter,QStringList bookCoverPath,QStringList booktitle,QList<myQRect*> *rect);
    void drawCurrentBookAuthor(QPainter *painter,QString bookAuthor,myQRect* rect);
    void drawCurrentBookProgress(QPainter *painter,int percentage,myQRect* rect);
//    void drawThreeBooksOfCurrentPage(QPainter *painter,QList<>)

    void drawLastPage(QPainter *painter,myQRect* rect,bool firstpage);
    void drawNextPage(QPainter *painter,myQRect* rect,bool endpage);
    void drawTextView(QPainter *painter,myQRect* rect,QString title);
    void drawThreeModulesBottom1(QPainter *painter,myQRect* rect);
    void drawThreeModulesBottom2(QPainter *painter,myQRect* rect);
    void drawThreeModulesBottom3(QPainter *painter,myQRect* rect);
    void drawThreeBooksArea(QPainter *painter,QList<myQRect*> *rectlist,QList<localDirectoryItem> *booklist);





};

#endif // DRAWMAINPAGE_H
