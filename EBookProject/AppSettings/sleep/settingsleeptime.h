#ifndef SETTINGSLEEPTIME_H
#define SETTINGSLEEPTIME_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QPainter>
#include<QPaintEvent>
#include"statusbar.h"
#include"statusbar_global.h"
#include"drawsettingsleep.h"
#include"utils/redefineqrect.h"
#include"syssettings.h"

class SettingSleepTime : public QMainWindow
{
    Q_OBJECT
public:
    explicit SettingSleepTime(QWidget *parent = 0);
    ~SettingSleepTime();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    void init();
    void initView();
    void initConnections();
    StatusBar *statusbar;
    drawSettingSleep *drawsettingsleep;
    QList<myQRect*> *rectlist;
    myQRect *myqrect;

    int targetwidgetIndex;
    int time_selected;
    SysSettings *mysyssetting;




signals:

public slots:
};

#endif // SETTINGSLEEPTIME_H
