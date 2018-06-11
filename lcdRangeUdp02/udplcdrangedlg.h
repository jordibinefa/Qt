#ifndef UDPLCDRANGEDLG_H
#define UDPLCDRANGEDLG_H

#include <QDialog>
#include "lcdrange.h"

#include <QtNetwork>

class QUdpSocket;
class QHostAddress;

namespace Ui {
    class udpLcdRangeDlg;
}

class udpLcdRangeDlg : public QDialog
{
    Q_OBJECT

public:
    explicit udpLcdRangeDlg(QWidget *parent = 0);
    ~udpLcdRangeDlg();

private:
    Ui::udpLcdRangeDlg *ui;
    LCDRange *lcdR;
    void vTrametSocolUdp(QByteArray datagram,QHostAddress adreca,quint16 port);
    QHostAddress qha;
    quint16 nPort;

private slots:
    void vSendUdp(int);
};

#endif // UDPLCDRANGEDLG_H
