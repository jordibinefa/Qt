#ifndef UDPDLG_H
#define UDPDLG_H

//#include <QtGui/QDialog> // <-- Qt4
#include <QtWidgets/QDialog> // <-- Qt5
#include <QtNetwork>

namespace Ui
{
    class UDPdlg;
}

class UDPdlg : public QDialog
{
    Q_OBJECT

public:
    UDPdlg(QWidget *parent = 0);
    ~UDPdlg();

private:
    Ui::UDPdlg *ui;
    QUdpSocket *udpSocketUdpRx;
    void vInterpretaTramaRebudaUdp(QByteArray datagrama,QHostAddress adrecaOrigen);
    void vEscriuTramesUdp(QByteArray datagrama,QHostAddress adrecaOrigen);
    void vTrametSocolUdp(QByteArray datagram,QHostAddress adreca,quint16 port);

private slots:
    void on_botIntercanvi_clicked();
    void on_botTx_clicked();
    void slotMiroSiHiHaText(QString);
    void vDatagramaUdpRxRebut();
    void slotCanviaPortRx(QString);
};

#endif // UDPDLG_H
