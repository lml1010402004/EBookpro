#include "languagekeyboard.h"
#include"application.h"

LanguageKeyboard::LanguageKeyboard(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);

    init();

}

LanguageKeyboard::~LanguageKeyboard()
{

}

void LanguageKeyboard::mousePressEvent(QMouseEvent *event)
{
this->close();
}

void LanguageKeyboard::mouseMoveEvent(QMouseEvent *event)
{

}

void LanguageKeyboard::mouseReleaseEvent(QMouseEvent *event)
{

}

void LanguageKeyboard::init()
{

}
