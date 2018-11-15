#include "ginyudp.h"
#include "ui_ginyudp.h"

#include <QDebug>

GinyUDP::GinyUDP(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GinyUDP)
{
    ui->setupUi(this);
    nPort = PORT_BY_DEFAULT;
    udpSocketEscoltador = NULL;
    vCanviaPort(nPort);
}

GinyUDP::~GinyUDP()
{
    delete ui;
}

bool GinyUDP::bInitSocket(quint16 nP){
    bool bRunning;

    if(udpSocketEscoltador){
        udpSocketEscoltador->deleteLater();
        disconnect(udpSocketEscoltador);
        delete udpSocketEscoltador;
        udpSocketEscoltador = NULL;
    }
    udpSocketEscoltador = new QUdpSocket(this);
    //udpSocketEscoltador->bind(QHostAddress::LocalHost, nPort);
    bRunning = udpSocketEscoltador->bind(QHostAddress::AnyIPv4, nP);


    connect(udpSocketEscoltador, SIGNAL(readyRead()),
            this, SLOT(vlecturaDatagramesPendents()));

    return bRunning;
}

void GinyUDP::vCanviaPort(int nP){
    nPort = (quint16)nP;

    QString qsz;
    if(bInitSocket(nPort)){
        qsz = "Rx Port: " + QString::number(nPort);
        ui->etInfo->setStyleSheet("QLabel { color : green; }");
    }else{
        qsz = "Rx Port " + QString::number(nPort) +" ocupat";
        ui->etInfo->setStyleSheet("QLabel { color : red; }");
    }
    ui->etInfo->setText(qsz);
}

void GinyUDP::vlecturaDatagramesPendents(){
    qDebug() << "Un datagrama";
    while (udpSocketEscoltador->hasPendingDatagrams()) {
        QNetworkDatagram datagram = udpSocketEscoltador->receiveDatagram();
        vProcessaDatagrama(datagram);
    }
}

void GinyUDP::vProcessaDatagrama(QNetworkDatagram datagram){
    QByteArray qbaDatagrama = datagram.data();

    QString qsz = "Des de " + datagram.senderAddress().toString() + ": ";
    qsz += qbaDatagrama;

    qDebug() << qsz;

    qsz = "Des de <font color=\"red\">" + datagram.senderAddress().toString() + "</font>: ";
    qsz += "<font color=\"blue\">" + qbaDatagrama + "</font>";
    ui->plainTextEdit->appendHtml(qsz);
}
