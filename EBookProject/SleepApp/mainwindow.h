#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define FIXED_WIDTH 600
#define FIXED_HEIGHT 800

#include <QDialog>
#include <QPainter>
#include <QString>
#include <QRectF>
#include <QPixmap>
#include <QLineF>
#include <QRect>
#include <QFont>
#include <QKeyEvent>
//#include "lcd_backlight.h"
#include"syssettings.h"





class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0,char *arg[]=0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);

    void drawBackground();
    void keyPressEvent(QKeyEvent *event);

    void init();


private slots:
    void HanderSleep();


private:
    SysSettings *setting;
    QPainter *painter;
    QPixmap pixmap;
    const static int WORK_TIMER_OUT = 200;
    QTimer* m_workTimer;
//    Lcd_backlight m_lcdbacklight;
//    int flag ;
    QRect rect;
    bool flag_shutdown;

};

#endif // MAINWINDOW_H
