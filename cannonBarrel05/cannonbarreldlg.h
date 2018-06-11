#ifndef CANNONBARRELDLG_H
#define CANNONBARRELDLG_H

#include <QDialog>

#include <QtNetwork>

class QUdpSocket;
class QHostAddress;
class QByteArray;

namespace Ui {
    class cannonBarrelDlg;
}

class cannonBarrelDlg : public QDialog
{
    Q_OBJECT

public:
    explicit cannonBarrelDlg(QWidget *parent = 0);
    ~cannonBarrelDlg();

private:
    Ui::cannonBarrelDlg *ui;

    void initSocket();

    QUdpSocket *udpSocket;
    QHostAddress qha;
    quint16 nPort;
    void processTheDatagram(QByteArray datagram, QHostAddress qha);
    void vListIPaddress();

private slots:
    void readPendingDatagrams();
    void updateUdpPort(QString);

signals:
    void newAngle(int angle);
};

#endif // CANNONBARRELDLG_H
