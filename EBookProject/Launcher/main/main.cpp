#include"HomePage/mainwindow.h"
#include<QApplication>
#include<QTextCodec>
#include<QFont>
#include"Application/keyboard.h"
#include"Application/keyboardfilter.h"
#include"Application/pinyinim.h"
KeyBoardFilter *keyboardfilter;

int main(int argc,char *argv[]){

    QApplication app(argc,argv);
    QApplication::setScreenUpdateMode(QApplication::EINK_GC16_LOCAL_MODE);
    //设置支持汉字字体显示==开始===
    QFont font;
    font.setFamily(("Microsoft YaHei"));
     app.setFont(font);
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

    return app.exec();

}
