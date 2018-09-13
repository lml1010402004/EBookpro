#ifndef USBTRANSFER_H
#define USBTRANSFER_H

#include <QMainWindow>

class UsbTransfer : public QMainWindow
{
    Q_OBJECT
public:
    explicit UsbTransfer(QWidget *parent = 0);
    ~UsbTransfer();

private:
    void init();

signals:

public slots:
};

#endif // USBTRANSFER_H
