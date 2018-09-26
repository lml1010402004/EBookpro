#ifndef BOOKSHELF_H
#define BOOKSHELF_H

#include <QMainWindow>
#include<QPainter>
#include<QMouseEvent>
#include<QList>
#include"BookShelf/bookshelf.h"
#include<DataItem/conditionitem.h>
#include<DataBase/database.h>
#include"statusbar.h"
#include"statusbar_global.h"
#include"drawbookshelf.h"
#include"Utils/redefineqrect.h"
//#include"Application/pulldownwindow.h"
#include"commonutils.h"


class BookShelf : public QMainWindow
{
    Q_OBJECT
public:
    explicit BookShelf(QWidget *parent = 0);
    ~BookShelf();

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    QString getTheTargetBookPathforFBReader(int x_pos,int y_pos,QList<localDirectoryItem> *currentpagebookinfolist);



private:
    int current_page;
    int total_pages;
    int condition_selected_index;
    myQRect *myrect;
    ConditionItem conditionitem;
    QList<myQRect*> *rectlist;
    int targetwidgetindex;
    StatusBar *statusbar;
    DrawBookshelf *drawbookshelf;
    QList<ConditionItem> *conditonsItemlist;
    QList<QString> list;
    QList<localDirectoryItem> *totalbookinfolist;
    QList<localDirectoryItem> *currentpagebookinfolist;

    QList<QRect*> *nineareas;
    QRect *myqrect;
    commonUtils *commonutils;
    int targetbookindex;



    void init();
    void initView();

    void initConnection();
    QList<localDirectoryItem>* getCurrentPageBooklist(QList<localDirectoryItem> *list,int currentpage);
    int getTotalPagesForEachCondition(QList<localDirectoryItem> *list);
    void processFinisheds();

signals:
    void updateDataSignal();

public slots:
    void updateDataSlot();
};

#endif // BOOKSHELF_H
