#ifndef WALLPAPER_H
#define WALLPAPER_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QPainter>

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




signals:

public slots:
};

#endif // WALLPAPER_H
