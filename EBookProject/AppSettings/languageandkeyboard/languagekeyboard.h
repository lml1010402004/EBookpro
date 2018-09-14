#ifndef LANGUAGEKEYBOARD_H
#define LANGUAGEKEYBOARD_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QPainter>
#include<QPaintEvent>

class LanguageKeyboard : public QMainWindow
{
    Q_OBJECT
public:
    explicit LanguageKeyboard(QWidget *parent = 0);
    ~LanguageKeyboard();


    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
     void init();


signals:

public slots:
};

#endif // LANGUAGEKEYBOARD_H
