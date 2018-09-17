#ifndef LANGUAGEKEYBOARD_H
#define LANGUAGEKEYBOARD_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QPainter>
#include<QPaintEvent>
#include"statusbar.h"
#include"statusbar_global.h"
#include"drawlanguagekeyboard.h"
#include"utils/redefineqrect.h"
#include<QList>

class LanguageKeyboard : public QMainWindow
{
    Q_OBJECT
public:
    explicit LanguageKeyboard(QWidget *parent = 0);
    ~LanguageKeyboard();


    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);



private:
     void init();
     StatusBar *statusbar;
     DrawLanguagekeyboard *drawlanguagekeyboard;
     QList<myQRect*> *rectlist;
     myQRect *myqrect;



signals:

public slots:
};

#endif // LANGUAGEKEYBOARD_H
