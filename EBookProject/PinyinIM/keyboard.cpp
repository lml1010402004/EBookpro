#include <QtGui>
#include "keyboard.h"
#include "pinyinim.h"

static int KEY_COUNT = 33;
KeyButton m_KeyButtons[] = {
    {0, "q", "Q", "1", QRect(0, 80, 60, 80)},
    {1, "w", "W", "2", QRect(60, 80, 60, 80)},
    {2, "e", "E", "3", QRect(120, 80, 60, 80)},
    {3, "r", "R", "4", QRect(180, 80, 60, 80)},
    {4, "t", "T", "5", QRect(240, 80, 60, 80)},
    {5, "y", "Y", "6", QRect(300, 80, 60, 80)},
    {6, "u", "U", "7", QRect(360, 80, 60, 80)},
    {7, "i", "I", "8", QRect(420, 80, 60, 80)},
    {8, "o", "O", "9", QRect(480, 80, 60, 80)},
    {9, "p", "P", "0", QRect(540, 80, 60, 80)},

    {10, "a", "A", "@", QRect(30, 160, 60, 80)},
    {11, "s", "S", "#", QRect(90, 160, 60, 80)},
    {12, "d", "D", "$", QRect(150, 160, 60, 80)},
    {13, "f", "F", "%", QRect(210, 160, 60, 80)},
    {14, "g", "G", "*", QRect(270, 160, 60, 80)},
    {15, "h", "H", "-", QRect(330, 160, 60, 80)},
    {16, "j", "J", "/", QRect(390, 160, 60, 80)},
    {17, "k", "K", "(", QRect(450, 160, 60, 80)},
    {18, "l", "L", ")", QRect(510, 160, 60, 80)},

    {19, "SHIFT", "SHIFT", ",", QRect(0, 240, 90, 80)},
    {20, "z", "Z", "&", QRect(90, 240, 60, 80)},
    {21, "x", "X", "!", QRect(150, 240, 60, 80)},
    {22, "c", "C", "\"", QRect(210, 240, 60, 80)},
    {23, "v", "V", "\'", QRect(270, 240, 60, 80)},
    {24, "b", "B", ":", QRect(330, 240, 60, 80)},
    {25, "n", "N", ";", QRect(390, 240, 60, 80)},
    {26, "m", "M", "?", QRect(450, 240, 60, 80)},
    {27, "DEL", "DEL", "", QRect(510, 240, 90, 80)},

    {28, "SWITCH", "SWITCH", "", QRect(0, 320, 120, 80)},
    {29, "SYMBOL", "SYMBOL", "", QRect(120, 320, 90, 80)},
    {30, "SPACE", "SPACE", " ", QRect(210, 320, 180, 80)},
    {31, "PERIOD", "PERIOD", ".", QRect(390, 320, 90, 80)},
    {32, "ENTER", "ENTER", "", QRect(480, 320, 120, 80)},
};

QRect m_KeyRect = QRect(15, 5, 600, 35);
QRect m_LeftArrowRect[] = {QRect(15, 48, 10, 15), QRect(0, 40, 44, 78)};
QRect m_RightArrowRect[] = {QRect(570, 48, 10, 15), QRect(560, 40, 600, 78)};
QRect m_WordRect = QRect(44, 35, 30, 38);
QLineF m_LineF = QLineF(0, 78, 600, 78);
QRect m_KeyBoardRect = QRect(0, 80, 600, 320);

const QString DATAPATH  = "/usr/local/app/";

Keyboard::Keyboard(QWidget *parent, QWSInputMethod* im) : QDialog(0, Qt::Tool | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint)
{
    m_DB = QSqlDatabase::addDatabase("QSQLITE","ChineseInput");
    m_DB.setDatabaseName(DATAPATH+"pinyin.db");
    qDebug()<<"I am jack111111";
    if ( !m_DB.open())
    {
        qDebug() << "Open pinyin database failed!11111";
    }

    m_IsEnglishMode = true;
    m_IsLowerKey= true;
    m_IsSymbolMode = false;
    m_PageCount = 0;
    m_PageIndex = 0;

    connect(this, SIGNAL(sendKey(QString)), im, SLOT(confirmString(QString)));
    connect(this, SIGNAL(send_key(int , int, Qt::KeyboardModifiers, bool, bool)),
            im, SLOT(sendkeyevent(int , int, Qt::KeyboardModifiers, bool, bool)));
}

Keyboard::Keyboard() : QDialog(0, Qt::Tool | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint)
{
    m_DB = QSqlDatabase::addDatabase("QSQLITE","ChineseInput");
    m_DB.setDatabaseName(DATAPATH+"pinyin.db");
    qDebug()<<"I am jack2222";
    if ( !m_DB.open())
    {
        qDebug() << "Open pinyin database failed!2222222";
    }

    m_IsEnglishMode = true;
    m_IsLowerKey= true;
    m_IsSymbolMode = false;
    m_PageCount = 0;
    m_PageIndex = 0;
}


Keyboard::~Keyboard()
{
    m_DB.close();
    delete m_Event;
    delete m_Painter;
}

QString Keyboard::queryChineseWords(QString key)
{
    QString result;
    QSqlQuery query(m_DB);
    query.prepare("SELECT * FROM zhcn WHERE py=?");
    query.addBindValue(key);
    qDebug()<<"1234567890=="+key;
    if(query.isNull(1)){
        qDebug()<<"query is null";
    }

    if(!query.exec())
    {
        qDebug() << "Query pinyin database failed!";
    }

    while(query.next())
    {
        result.append(query.value(2).toString());
    }

    return result;
}

void Keyboard::showChineseWordsForKey(QString key)
{
    if ((!key.isEmpty() && !key.isNull()))
    {
        m_Key.append(key);
    }

    m_ChineseWords.clear();
    m_ChineseWords = queryChineseWords(m_Key);
    m_ChineseWordsRect.clear();
    m_PageIndex = 0;
    m_PageCount = m_ChineseWords.size() / PAGE_SIZE;
    if (m_ChineseWords.size() % PAGE_SIZE != 0)
    {
        m_PageCount += 1;
    }

    if ((!m_Key.isEmpty() && !m_Key.isNull()) || (!m_ChineseWords.isEmpty() && !m_ChineseWords.isNull()))
    {
        this->repaint();
    }
}

void Keyboard::paintEvent(QPaintEvent *event)
{
    m_Painter = new QPainter(this);

    m_Font.setPointSize(12);
    m_Painter->setFont(m_Font);
    m_Painter->drawText(m_KeyRect, m_Key);

    m_Font.setPointSize(15);
    m_Painter->setFont(m_Font);
    if (m_PageCount > 1)
    {
        QPixmap arrow;
        arrow.load(":/pics/keyboard_left_arrow.png");
        m_Painter->drawPixmap(m_LeftArrowRect[0], arrow);
        arrow.load(":/pics/keyboard_right_arrow.png");
        m_Painter->drawPixmap(m_RightArrowRect[0], arrow);

        int index = 0;
        int count = (m_PageIndex + 1) * PAGE_SIZE;
        if (count > m_ChineseWords.size())
        {
            count = m_ChineseWords.size();
        }
        for (int i = m_PageIndex * PAGE_SIZE; i < count; i++)
        {
            QRect rect = QRect(m_WordRect.x() * (index + 1), m_WordRect.y(), m_WordRect.width(), m_WordRect.height());
            m_ChineseWordsRect.insert(i, rect);
            m_Painter->drawText(rect, m_ChineseWords.at(i));
            index++;
        }
    }
    else
    {
        for (int i = 0; i < m_ChineseWords.size(); i++)
        {
            QRect rect = QRect(m_WordRect.x() * (i + 1), m_WordRect.y(), m_WordRect.width(), m_WordRect.height());
            m_ChineseWordsRect.insert(i, rect);
            m_Painter->drawText(rect, m_ChineseWords.at(i));
        }
    }

    m_Painter->drawLine(m_LineF);

    if (m_IsEnglishMode)
    {
        if (m_IsSymbolMode)
        {
            m_PixmapKeyboard.load(":/pics/keyboard_en_symbol.png");
        }
        else
        {
            if (m_IsLowerKey)
            {
                m_PixmapKeyboard.load(":/pics/keyboard_en_lower.png");
            }
            else
            {
                m_PixmapKeyboard.load(":/pics/keyboard_en_upper.png");
            }
        }
    }
    else
    {
        if (m_IsSymbolMode)
        {
            m_PixmapKeyboard.load(":/pics/keyboard_cn_symbol.png");
        }
        else
        {
            m_PixmapKeyboard.load(":/pics/keyboard_cn.png");
        }
    }

    m_Painter->drawPixmap(m_KeyBoardRect, m_PixmapKeyboard);
}

void Keyboard::mousePressEvent(QMouseEvent *event)
{
    if (m_PageCount > 1)
    {
        int l_left = m_LeftArrowRect[1].x();
        int l_right = m_LeftArrowRect[1].width();
        int l_top = m_LeftArrowRect[1].y();
        int l_bottom = m_LeftArrowRect[1].height();
        int r_left = m_RightArrowRect[1].x();
        int r_right = m_RightArrowRect[1].width();
        int r_top = m_RightArrowRect[1].y();
        int r_bottom = m_RightArrowRect[1].height();

        if (event->x() >= l_left && event->x() <= l_right && event->y() >= l_top && event->y() <= l_bottom)
        {
            if (m_PageIndex > 0)
            {
                m_PageIndex--;
                //qDebug() << "===== On click prev page index: " << m_PageIndex;
                this->repaint();
                return;
            }
        }
        else if (event->x() >= r_left && event->x() <= r_right && event->y() >= r_top && event->y() <= r_bottom)
        {
            if (m_PageIndex < m_PageCount - 1)
            {
                m_PageIndex++;
                //qDebug() << "===== On click next page index: " << m_PageIndex;
                this->repaint();
                return;
            }
        }
    }

    for (int i = 0; i < m_ChineseWordsRect.size(); i++)
    {
        QRect rect = m_ChineseWordsRect.value(i);
        int left = rect.x();
        int right = left + rect.width();
        int top = rect.y();
        int bottom = top + rect.height();

        if (event->x() >= left && event->x() <= right && event->y() >= top && event->y() <= bottom)
        {
            int index = i + m_PageIndex * PAGE_SIZE;
            if (m_ChineseWords.size() > 0 && index <= m_ChineseWords.size())
            {
                //qDebug() << "===== On click word index: " << index;
                affirmString(m_ChineseWords.at(index));
                m_ChineseWords.clear();
                m_ChineseWordsRect.clear();
                m_Key.clear();
                m_PageCount = 0;
                m_PageIndex = 0;
                this->repaint();
            }
            return;
        }
    }

    for (int i = 0; i < KEY_COUNT; i++)
    {
        KeyButton button = m_KeyButtons[i];
        int left = button.Rect.x();
        int right = left + button.Rect.width();
        int top = button.Rect.y();
        int bottom = top + button.Rect.height();

        if (event->x() >= left && event->x() <= right && event->y() >= top && event->y() <= bottom)
        {
            //qDebug() << "===== On click button index: " << button.Index;
            //qDebug() << "===== m_IsEnglishMode: " << m_IsEnglishMode << ", m_IsLowerKey: " << m_IsLowerKey << ", m_IsSymbolMode: " << m_IsSymbolMode;

            if (button.Lower.indexOf(QString("SWITCH")) != -1)
            {
                accept_Switch();
                return;
            }
            else if (button.Lower.indexOf(QString("SYMBOL")) != -1)
            {
                accept_Symbol();
                return;
            }
            else if (button.Lower.indexOf(QString("DEL")) != -1)
            {
                accept_Del();
                return;
            }
            else if (button.Lower.indexOf(QString("ENTER")) != -1)
            {
                accept_Enter();
                return;
            }

            if (m_IsSymbolMode)
            {
                affirmString(button.Symbol);
            }
            else
            {
                if (button.Lower.indexOf(QString("SPACE")) != -1 || button.Lower.indexOf(QString("PERIOD")) != -1)
                {
                    affirmString(button.Symbol);
                    return;
                }

                if (m_IsEnglishMode)
                {
                    if (button.Lower.indexOf(QString("SHIFT")) != -1)
                    {
                        m_IsLowerKey = !m_IsLowerKey;
                        this->repaint();
                    }
                    else
                    {
                        affirmString(m_IsLowerKey ? button.Lower : button.Upper);
                    }
                }
                else
                {
                    if (button.Lower.indexOf(QString("SHIFT")) != -1)
                    {
                        affirmString(button.Symbol);
                    }
                    else
                    {
                        showChineseWordsForKey(button.Lower);
                    }
                }
            }
            return;
        }
    }
}

void Keyboard::accept_Switch()
{
    m_IsEnglishMode = !m_IsEnglishMode;
    m_IsLowerKey = true;
    m_ChineseWords.clear();
    m_ChineseWordsRect.clear();
    m_Key.clear();
    m_PageCount = 0;
    m_PageIndex = 0;
    this->repaint();
}

void Keyboard::accept_Symbol()
{
    m_IsSymbolMode = !m_IsSymbolMode;
    m_ChineseWords.clear();
    m_ChineseWordsRect.clear();
    m_Key.clear();
    m_PageCount = 0;
    m_PageIndex = 0;
    this->repaint();
}

void Keyboard::accept_Del()
{
    if (m_IsEnglishMode)
    {
        //QApplication::sendEvent(QApplication::focusWidget(), m_Event);
        send_funckey(0, Qt::Key_Backspace, Qt::NoModifier, true, false);
        send_funckey(0, Qt::Key_Backspace, Qt::NoModifier, false, false);
    }
    else
    {
        if (!m_Key.isEmpty() && !m_Key.isNull())
        {
            m_Key.remove(m_Key.size() - 1, 1);

            if (!m_Key.isEmpty() && !m_Key.isNull())
            {
                showChineseWordsForKey("");
            }
            else
            {
                m_ChineseWords.clear();
                m_ChineseWordsRect.clear();
                m_Key.clear();
                m_PageCount = 0;
                m_PageIndex = 0;
                this->repaint();
            }
        }
        else
        {
            //QApplication::sendEvent(QApplication::focusWidget(), m_Event);
            send_funckey(0, Qt::Key_Backspace, Qt::NoModifier, true, false);
            send_funckey(0, Qt::Key_Backspace, Qt::NoModifier, false, false);
        }
    }
}

void Keyboard::accept_Enter()
{
    //m_Event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier);

    if (m_IsEnglishMode)
    {
        //QApplication::sendEvent(QApplication::focusWidget(), m_Event);
        send_funckey(0, Qt::Key_Enter, Qt::NoModifier, true, false);
        send_funckey(0, Qt::Key_Enter, Qt::NoModifier, false, false);
    }
    else
    {
        if (m_ChineseWords.size() > 0)
        {
            affirmString(m_ChineseWords.at(0));
            m_ChineseWords.clear();
            m_ChineseWordsRect.clear();
            m_Key.clear();
            m_PageCount = 0;
            m_PageIndex = 0;
           this->repaint();
        }
        else
        {
            //QApplication::sendEvent(QApplication::focusWidget(), m_Event);
            send_funckey(0, Qt::Key_Enter, Qt::NoModifier, true, false);
            send_funckey(0, Qt::Key_Enter, Qt::NoModifier, false, false);
        }
    }
}

void Keyboard::affirmString(QString value)
{
    emit sendKey(value);
}

void Keyboard::send_funckey(int unicode, int keycode, Qt::KeyboardModifiers modifiers,
                  bool isPress, bool autoRepeat)
{
    //qDebug()<<"Keyboard::send_funckey key="<<keycode;
    emit send_key(unicode, keycode, modifiers, isPress, autoRepeat);
}
