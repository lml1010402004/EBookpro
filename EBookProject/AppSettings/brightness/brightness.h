#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#include<QMainWindow>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QPainter>

class Brightness : public QMainWindow
{
    Q_OBJECT
public:
    explicit Brightness(QWidget *parent = 0);
    ~Brightness();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


private:
    void init();
    void initView();
    void initConnections();



signals:

public slots:
};

#endif // BRIGHTNESS_H
