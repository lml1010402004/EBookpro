#ifndef PINYINIM_H
#define PINYINIM_H
#include <QWSInputMethod>
#include"Application/keyboard.h"
#include"Application/keyboardfilter.h"

class PinyinIM : public QWSInputMethod
{
    Q_OBJECT

public:
    static PinyinIM* getInstance(QWidget *parent);
    PinyinIM(QWidget *parent);
    PinyinIM();
    ~PinyinIM();
    void updateHandler(int);

signals:
    void sigConfirmString(QString key);
    void sendkey(int unicode, int keycode, Qt::KeyboardModifiers modifiers,
                      bool isPress, bool autoRepeat);

public slots:
    void confirmString(QString key);
    void sendkeyevent(int unicode, int keycode, Qt::KeyboardModifiers modifiers,
                      bool isPress, bool autoRepeat);
private:
    static PinyinIM* m_Instance;
    Keyboard *m_Keyboard;

};

#endif // PINYINIM_H
