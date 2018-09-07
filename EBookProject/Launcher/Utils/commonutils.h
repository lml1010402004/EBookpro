#ifndef COMMONUTILS_H
#define COMMONUTILS_H

#include<sys/statfs.h>
#include<QString>
#include<QList>
#include<DataBase/database.h>
#include<QProcess>
#include<QStringList>
#include<QPainter>
#include<QRect>
#include<QList>
#include<QMainWindow>
#include"Utils/redefineqrect.h"





class commonUtils
{

public:
    commonUtils();
    static int getStorageOfDevice();
    static QString GetLocalMac();

    static  QList<localDirectoryItem>* getCurrentPageBooks(QList<localDirectoryItem> *list,int currentPage,int pagesize);
    void openBookFromFBreader(QProcess *process,QString bookpath);

    void drawProgressBarOpeningBook(QPainter *painter);

    int getTheBatteryPercentage();

    static int getTheTargetWidget(int pos_x,int pos_y,QList<myQRect*> *listrect);

    static void formattingDisk();
    static void backToHomePageSlot();
    static int returnLightValue(int progress);


private:

    QStringList arguments;



};

#endif // COMMONUTILS_H
