#ifndef GINYUDP_H
#define GINYUDP_H

#include <QWidget>

#include <QUdpSocket>
#include <QNetworkDatagram>

#define PORT_BY_DEFAULT 3333

namespace Ui {
class GinyUDP;
}

class GinyUDP : public QWidget
{
    Q_OBJECT

public:
    explicit GinyUDP(QWidget *parent = nullptr);
    ~GinyUDP();

protected:
    bool bInitSocket(quint16 nP);
    void vProcessaDatagrama(QNetworkDatagram datagram);

private:
    Ui::GinyUDP *ui;
    QUdpSocket *udpSocketEscoltador;
    qint16 nPort;

public slots:
    void vlecturaDatagramesPendents();
    void vCanviaPort(int);
};

#endif // GINYUDP_H
