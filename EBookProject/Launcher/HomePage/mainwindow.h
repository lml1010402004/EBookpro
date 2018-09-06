#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QPainter>
#include<QList>
#include<QRect>
#include<QRect>
#include"drawmainpage.h"
//#include"modulepages/pulldownwindow.h"
#include"statusbar.h"
#include"statusbar_global.h"
#include<QStringList>
#include"Setting/settings.h"
#include"DataBase/database.h"
#include"BookShelf/bookshelf.h"
#include"ThirdApp/thirdapplications.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


    void paintEvent(QPaintEvent *event);

private:
    DrawMainPage *drawmainpage;
//    PullDownWindow *pulldownwindow;
    StatusBar *statusbar;
//    Settings *settings;
    BookShelf *bookshelf;
    ThirdApplications *thirdapplication;





    QStringList currentbookcoverlist;
    QStringList currentbookcovertitle;
    QStringList threebookstringlist;
    QList<QRect> *currentbookcoverrect;
    QList<QRect> *threebookrect;
    QList<localDirectoryItem> *totaltemp;
    int currentPageOfMainPage ;
    int unable_next;
    int unable_last;
    bool firstpage;
    bool endpage;

private:
    void init();
    void initView();
    void initConnection();

    void getBookDataFromDataBase();

    QRect rect;
    int targetWidgetIndex;
    int totalPagesOfBooks;
    QList<localDirectoryItem>  *currentPagebooklist;



    QList<QRect> *rectlist;





};

#endif // MAINWINDOW_H
