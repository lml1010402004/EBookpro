#include "pinyinim.h"

PinyinIM* PinyinIM::m_Instance = NULL;

PinyinIM* PinyinIM::getInstance(QWidget *parent)
{
    if(m_Instance)
    {
        return m_Instance;
    }

    m_Instance = new PinyinIM(parent);
    return m_Instance;
}

PinyinIM::PinyinIM(QWidget *parent)
{
    m_Keyboard = new Keyboard(parent, this);
}

PinyinIM::PinyinIM()
{
    m_Keyboard = new Keyboard();
    connect(m_Keyboard, SIGNAL(sendKey(QString)), this, SLOT(confirmString(QString)));
    connect(m_Keyboard, SIGNAL(send_key(int , int, Qt::KeyboardModifiers, bool, bool)),
            this, SLOT(sendkeyevent(int , int, Qt::KeyboardModifiers, bool, bool)));
}

PinyinIM::~PinyinIM()
{
    m_Keyboard->deleteLater();
}

void PinyinIM::confirmString(QString key)
{
    sendCommitString(key);
    emit sigConfirmString(key);
}

void PinyinIM::sendkeyevent(int unicode, int keycode, Qt::KeyboardModifiers modifiers,
                  bool isPress, bool autoRepeat)
{
    sendKeyEvent(unicode, keycode, modifiers, isPress, autoRepeat);
    emit sendkey(unicode, keycode, modifiers, isPress, autoRepeat);
}


void PinyinIM::updateHandler(int type)
{
    switch(type)
    {
        case QWSInputMethod::FocusIn:
            m_Keyboard->show();
            m_Keyboard->setGeometry(QRect(0, 400, 600, 400));
            break;
        case QWSInputMethod::FocusOut:
            m_Keyboard->hide();
            break;
        default:
            break;
    }
}
