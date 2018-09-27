#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QPainter>
#include<QList>
#include<QRect>
#include"drawmainpage.h"
#include"statusbar.h"
#include"statusbar_global.h"
#include<QStringList>
#include"Setting/settings.h"
#include"DataBase/database.h"
#include"BookShelf/bookshelf.h"
#include"ThirdApp/thirdapplications.h"
#include<QProcess>
#include"Utils/commonutils.h"
#include"syssettings.h"




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
    StatusBar *statusbar;
    BookShelf *bookshelf;

    ThirdApplications *thirdapplication;


    commonUtils *commonutils;
    SysSettings *mysyssettings;






    QStringList currentbookcoverlist;
    QStringList currentbookcovertitle;
    QStringList threebookstringlist;
    QList<myQRect*> *currentbookcoverrect;
    QList<myQRect*> *threebookrect;
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


    void operateMainPagetwobooks();



    void getBookDataFromDataBase();
    void assignDynamicRectstoThreerect(int size);


    int targetWidgetIndex;
    int totalPagesOfBooks;
    QList<localDirectoryItem>  *currentPagebooklist;




    QList<myQRect*> *rectlist;
    myQRect *myrect;

signals:
public slots:
    void processFinished(int value);





};

#endif // MAINWINDOW_H
