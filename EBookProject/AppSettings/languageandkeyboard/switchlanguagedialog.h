#ifndef SWITCHLANGUAGEDIALOG_H
#define SWITCHLANGUAGEDIALOG_H
#include<QDialog>
#include<QPaintEvent>
#include<QMouseEvent>
#include<QList>
#include<QPainter>
#include<utils/redefineqrect.h>
#include<QString>
#include"drawswitchlanguagesdialog.h"

class SwitchLanguageDialog:public QDialog
{Q_OBJECT
public:
    SwitchLanguageDialog();
    ~SwitchLanguageDialog();

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


private:
    void init();
    QList<myQRect*> *rectlist;
    myQRect *myqrect;
    DrawSwitchLanguagesDialog *drawswitchdialog;



signals:
    void closeLanguagesDialog();






};

#endif // SWITCHLANGUAGEDIALOG_H
