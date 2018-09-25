#ifndef SETTIMEDIALOG_H
#define SETTIMEDIALOG_H
#include<QMainWindow>
#include<QMouseEvent>
#include<QLineEdit>
#include<QWidget>
#include"drawsettimedialog.h"
#include<QList>
#include"utils/redefineqrect.h"

class SetTimeDialog:public QMainWindow
{
    Q_OBJECT
public:
    SetTimeDialog(QWidget *parent = 0);
    ~SetTimeDialog();
    void init();
    void initView();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


private:

    void setDateandHourIntoSystem(QString time);

    QLineEdit *mylineedit1;
    QLineEdit *mylineedit2;
    DrawSettimeDialog *drawsettimedialog;
    QList<myQRect*> *rectlist;
    myQRect *myqrect;
    int targetwidgetIndex;


signals:
    void closeWindows();


};

#endif // SETTIMEDIALOG_H
