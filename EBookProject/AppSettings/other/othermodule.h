#ifndef OTHERMODULE_H
#define OTHERMODULE_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QMouseEvent>
#include<QPainter>


class OtherModule : public QMainWindow
{
    Q_OBJECT
public:
    explicit OtherModule(QWidget *parent = 0);
    ~OtherModule();
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    void init();

signals:

public slots:
};

#endif // OTHERMODULE_H
