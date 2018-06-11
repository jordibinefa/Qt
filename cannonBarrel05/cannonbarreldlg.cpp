#include "cannonbarreldlg.h"
#include "ui_cannonbarreldlg.h"

#include "cannonfield.h"

#include <QDebug>

cannonBarrelDlg::cannonBarrelDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cannonBarrelDlg)
{
    ui->setupUi(this);
    CannonField *cannonField = new CannonField;
    ui->verticalLayout->addWidget(cannonField);
    nPort = 33333;
    ui->lineEditPort->setText(QString::number(nPort));
    initSocket();
    connect(ui->lineEditPort,SIGNAL(textChanged(QString)),this,SLOT(updateUdpPort(QString)));
    connect(this,SIGNAL(newAngle(int)),cannonField,SLOT(setAngle(int)));
    vListIPaddress();
 }

cannonBarrelDlg::~cannonBarrelDlg()
{
    delete ui;
}

void cannonBarrelDlg::initSocket()
{
    udpSocket = new QUdpSocket(this);
//    udpSocket->bind(QHostAddress::LocalHost, 33333);
    udpSocket->bind(QHostAddress::Any, nPort);

    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(readPendingDatagrams()));
}

void cannonBarrelDlg::readPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        udpSocket->readDatagram(datagram.data(), datagram.size(),
                                &sender, &senderPort);

        processTheDatagram(datagram,sender);
    }
}

void cannonBarrelDlg::processTheDatagram(QByteArray datagram, QHostAddress qha){
    bool ok;
    int n = datagram.toInt(&ok,10);
    QString qsz;
    if(ok){
        emit newAngle(n);
        if ( (n < 5) || (n > 70))
            qsz = trUtf8("%1 <font color = red>%2</color>").
                  arg(qha.toString()).
                  arg(datagram.data());
        else
            qsz = trUtf8("%1 <font color = blue>%2</color>").
                  arg(qha.toString()).
                  arg(datagram.data());
    }else
        qsz = trUtf8("%1 <font color = red>%2</color>").
              arg(qha.toString()).
              arg(datagram.data());
    ui->plainTextEdit->appendHtml(qsz);
}

void cannonBarrelDlg::updateUdpPort(QString qsz){
    bool ok;
    qint16 n = qsz.toInt(&ok,10);

    if(ok){
        disconnect(udpSocket);
        udpSocket->abort();
        delete udpSocket;
        nPort = n;
        initSocket();
    }
}

void cannonBarrelDlg::vListIPaddress(){
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (/*ipAddressesList.at != QHostAddress::LocalHost &&*/
            ipAddressesList.at(i).protocol() == QAbstractSocket::IPv4Protocol)

            {
                qDebug() << trUtf8("ipAddress : %1").
                        arg(ipAddressesList.at(i).toString());
                //break;
            }
    }
}
