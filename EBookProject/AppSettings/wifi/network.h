#ifndef NETWORK_H
#define NETWORK_H

#include <QMainWindow>

class Network : public QMainWindow
{
    Q_OBJECT
public:
    explicit Network(QWidget *parent = 0);
    ~Network();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    void init();
    void initView();

signals:

public slots:
};

#endif // NETWORK_H
