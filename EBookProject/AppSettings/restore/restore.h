#ifndef RESTORE_H
#define RESTORE_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QMouseEvent>
#include<QPainter>
#include<QList>
#include"utils/redefineqrect.h"
#include"drawrestore.h"
#include"confirmdialog.h"
#include"statusbar.h"
#include"statusbar_global.h"

class Restore : public QMainWindow
{
    Q_OBJECT
public:
    explicit Restore(QWidget *parent = 0);
    ~Restore();
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    void init();
    void initView();
    QList<myQRect*> *rectlist;
    myQRect *myqrect;
    DrawRestore *drawrestore;
    int targetwidgetIndex ;
    confirmDialog *myconfirmdialog;
    StatusBar *statusbar;

signals:

public slots:
};

#endif // RESTORE_H
