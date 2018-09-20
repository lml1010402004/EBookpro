#include "mainwindow/mainwindow.h"
#include<QApplication>
#include<QTextCodec>
#include<QFont>
#include"application/pinyinim.h"
#include"application/keyboardfilter.h"

KeyBoardFilter *keyboardfilter;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //设置支持汉字字体显示==开始===
    QFont font;
    font.setFamily(("Microsoft YaHei"));
     a.setFont(font);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    //设置支持汉字显示==结束==

    PinyinIM   *pinyinIM = new PinyinIM();
    //pinyinIM->connect(pinyinIM, SIGNAL(sigConfirmString(QString)), this, SLOT(pinyinIMConfirmStringS(QString)));
    QWSServer::setCurrentInputMethod(pinyinIM);

    keyboardfilter = new KeyBoardFilter;

    QWSServer::addKeyboardFilter(keyboardfilter);


    MainWindow w;
    w.show();


    return a.exec();
}
