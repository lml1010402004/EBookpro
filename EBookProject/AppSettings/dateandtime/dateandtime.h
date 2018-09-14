#ifndef DATEANDTIME_H
#define DATEANDTIME_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QPaintEvent>

class DateAndTime : public QMainWindow
{
    Q_OBJECT
public:
    explicit DateAndTime(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void init();

signals:

public slots:
};

#endif // DATEANDTIME_H
