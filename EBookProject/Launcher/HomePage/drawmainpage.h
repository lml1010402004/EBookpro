#ifndef DRAWMAINPAGE_H
#define DRAWMAINPAGE_H

#include<QPainter>
#include<QString>
#include<QStringList>
#include<QList>
#include<QFont>
#include"DataBase/database.h"

class DrawMainPage
{
public:
    DrawMainPage();
    ~DrawMainPage();

    QFont font;


    void drawCurrentBookCover(QPainter *painter,QStringList bookCoverPath,QStringList booktitle,QList<QRect> *rect);
    void drawCurrentBookAuthor(QPainter *painter,QString bookAuthor,QRect rect);
    void drawCurrentBookProgress(QPainter *painter,int percentage,QRect rect);
//    void drawThreeBooksOfCurrentPage(QPainter *painter,QList<>)

    void drawLastPage(QPainter *painter,int index,QRect rect,bool firstpage);
    void drawNextPage(QPainter *painter,int index,QRect rect,bool endpage);
    void drawTextView(QPainter *painter,QRect rect,QString title);
    void drawThreeModulesBottom1(QPainter *painter,int index ,QRect rect);
    void drawThreeModulesBottom2(QPainter *painter,int index ,QRect rect);
    void drawThreeModulesBottom3(QPainter *painter,int index ,QRect rect);
    void drawThreeBooksArea(QPainter *painter,QList<QRect> *rectlist,QList<localDirectoryItem> *booklist);





};

#endif // DRAWMAINPAGE_H
