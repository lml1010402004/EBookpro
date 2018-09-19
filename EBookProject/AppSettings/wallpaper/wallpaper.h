#ifndef WALLPAPER_H
#define WALLPAPER_H
#include <QMainWindow>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QPainter>
#include"syssettings.h"
#include"drawwallpaper.h"
#include"utils/redefineqrect.h"
#include<QList>
#include"statusbar.h"
#include"statusbar_global.h"


class WallPaper : public QMainWindow
{
    Q_OBJECT
public:
    explicit WallPaper(QWidget *parent = 0);
    ~WallPaper();

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


private:
    void init();
    void initView();
    SysSettings *mysysseting;
    DrawWallPaper *drawwallpaper;
    int index_wallpaper;//scope 0,1,2
    QList<myQRect*> *rectlist;
    QList<myQRect*> *wallpaperlist;
    QList<myQRect*> *checkboxs;
    myQRect *rect;
     myQRect *myqrect;
    StatusBar *statusbar;
    int targetwidgetIndex;





signals:

public slots:
};

#endif // WALLPAPER_H
