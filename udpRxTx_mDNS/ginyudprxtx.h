#ifndef GINYUDPRXTX_H
#define GINYUDPRXTX_H

#include <QWidget>

#include "ginyudp.h"
#include "ginyudptramet.h"

namespace Ui {
class GinyUdpRxTx;
}

class GinyUdpRxTx : public QWidget
{
    Q_OBJECT

public:
    explicit GinyUdpRxTx(QWidget *parent = nullptr);
    ~GinyUdpRxTx();

protected:
    GinyUdpTramet *gUdpTx;
    GinyUDP *gUdpRx;

private:
    Ui::GinyUdpRxTx *ui;
};

#endif // GINYUDPRXTX_H
