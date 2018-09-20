#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <QDialog>
#include <QWSInputMethod>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QMap>
#include <QMouseEvent>
#include <QtSql>
#include <QDebug>

struct KeyButton
{
    int Index;
    QString Lower;
    QString Upper;
    QString Symbol;
    QRect Rect;
};

class Keyboard : public QDialog
{
    Q_OBJECT

public:
    Keyboard(QWidget *parent, QWSInputMethod* im);
    Keyboard();
    ~Keyboard();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:
    void sendKey(QString key);
    void send_key(int unicode, int keycode, Qt::KeyboardModifiers modifiers,
                  bool isPress, bool autoRepeat);

private:
    void accept_Switch();
    void accept_Symbol();
    void accept_Del();
    void accept_Enter();

    void affirmString(QString value);
    void send_funckey(int unicode, int keycode, Qt::KeyboardModifiers modifiers,
                      bool isPress, bool autoRepeat);
    void showChineseWordsForKey(QString key);
    QString queryChineseWords(QString key);

private:
    QPainter *m_Painter;
    QFont m_Font;
    QPixmap m_PixmapKeyboard;
    QString m_Key;
    QString m_ChineseWords;
    QMap<int, QRect> m_ChineseWordsRect;
    const static int PAGE_SIZE = 12;
    int m_PageCount;
    int m_PageIndex;
    QSqlDatabase m_DB;

    QKeyEvent *m_Event;
    bool m_IsEnglishMode;
    bool m_IsLowerKey;
    bool m_IsSymbolMode;
};

#endif // KEYBOARD_H
