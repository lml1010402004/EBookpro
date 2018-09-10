#ifndef WALLPAPER_H
#define WALLPAPER_H

#include <QMainWindow>
#include<QMouseEvent>
#include"utils/redefineqrect.h"
#include"drawwallpaper.h"
#include"statusbar.h"
#include"statusbar_global.h"


class Wallpaper : public QMainWindow
{
    Q_OBJECT
public:
    explicit Wallpaper(QWidget *parent = 0);
    ~Wallpaper();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    void init();
    void initView();
    myQRect backbutton,homebutton;

    DrawWallpaper *drawwallpaper;

    StatusBar *statusbar;

signals:

public slots:
};

#endif // WALLPAPER_H
