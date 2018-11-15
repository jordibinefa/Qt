#ifndef GINYUDPTRAMET_H
#define GINYUDPTRAMET_H

#include <QWidget>

namespace Ui {
class GinyUdpTramet;
}

class qMDNS;
class QHostInfo;

class GinyUdpTramet : public QWidget
{
    Q_OBJECT

public:
    explicit GinyUdpTramet(QWidget *parent = nullptr);
    ~GinyUdpTramet();

protected slots:
    void vSendUdpDatagram();
    void vRemoveInfo();
    void vShow_mDNS_IP(const QHostInfo& info);
    void vShowTimeOut();

private slots:
    void on_btSend_clicked();
    void on_lePort_textChanged(const QString &arg1);
    void on_cbR_clicked(bool checked);
    void on_cbG_clicked(bool checked);
    void on_cbB_clicked(bool checked);
    void on_cbLittleB_clicked(bool checked);

private:
    Ui::GinyUdpTramet *ui;
    QStringList qslDNSResolver(QString host);
    bool bSendUdpByteArray(QByteArray); // No serveix fent servir qMDNS
    void vSendUdpByteArray(QByteArray); // Aquí canviem la manera de fer, per adaptar-ho a qMDNS
    qMDNS* m_mDNS;
    void vShowIfUdpHasBeenSent(bool bSuccessfullySent);
    void vLookForIpFrom_mDNS_andSend(QString mDnsName);
    bool m_bSent;
    QByteArray m_qbaLast;

signals:
    void vTrametRxUdpPort(int);

};

#endif // GINYUDPTRAMET_H
