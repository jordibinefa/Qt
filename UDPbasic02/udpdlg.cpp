#include "udpdlg.h"
#include "ui_udpdlg.h"

UDPdlg::UDPdlg(QWidget *parent)
    : QDialog(parent), ui(new Ui::UDPdlg)
{
    bool ok;
    ui->setupUi(this);
    ui->lineEditTx->setFocus();
    ui->botTx->setEnabled(false);
    udpSocketUdpRx = new QUdpSocket(this);
    udpSocketUdpRx->bind(ui->lineEditPortRx->text().toInt(&ok,10));
    connect(udpSocketUdpRx, SIGNAL(readyRead()),this, SLOT(vDatagramaUdpRxRebut()));
}

UDPdlg::~UDPdlg()
{
    delete ui;
}

void UDPdlg::slotMiroSiHiHaText(QString qsz){
    if(qsz.length())
        ui->botTx->setEnabled(true);
    else
        ui->botTx->setEnabled(false);
}

void UDPdlg::vDatagramaUdpRxRebut(){
    while (udpSocketUdpRx->hasPendingDatagrams()) {
         QByteArray datagram;
         QHostAddress adrecaOrigen;
         quint16 portOrigen;
         datagram.resize(udpSocketUdpRx->pendingDatagramSize());
         udpSocketUdpRx->readDatagram(datagram.data(),datagram.size(),
                                 &adrecaOrigen,&portOrigen);
         vInterpretaTramaRebudaUdp(datagram,adrecaOrigen);
     }
}

void UDPdlg::vInterpretaTramaRebudaUdp(QByteArray datagrama,QHostAddress adrecaOrigen){
    ui->plainTextEdit->appendHtml(trUtf8("%1").arg(datagrama.data()));
    ui->plainTextEdit->ensureCursorVisible();
}

void UDPdlg::on_botTx_clicked(){
    QString qsz; bool ok;

    qsz = ui->lineEditTx->text();
    quint16 nPortTx= ui->lineEditPortTx->text().toInt(&ok,10);
    //vTrametSocolUdp(qsz.toAscii(), // <-- Qt4
    vTrametSocolUdp(qsz.toLatin1(),  // <-- Qt5
                    QHostAddress(ui->lineEditIP->text()),
                    nPortTx);
    //vEscriuTramesUdp(qsz.toAscii(),// <-- Qt4
    vEscriuTramesUdp(qsz.toLatin1(), // <-- Qt5
                      QHostAddress(ui->lineEditIP->text()));
}

void UDPdlg::vTrametSocolUdp(QByteArray datagram,QHostAddress adreca,quint16 port){
        QUdpSocket *udpSocketTX = new QUdpSocket(this);
        udpSocketTX->writeDatagram(datagram.data(),datagram.size(),adreca,port);
        delete udpSocketTX;
}

void UDPdlg::vEscriuTramesUdp(QByteArray datagrama,QHostAddress adrecaOrigen){
/*    QString qsz;

    qsz = trUtf8("UDPc Tx%1<font color= red> CLNT %2 : <font color= orange>%3").
                    arg(QDateTime::currentDateTime().toLocalTime().toString("yyyyMMddhhmmsszzz")).
                    arg(adrecaOrigen.toString()).
                    arg(datagrama.data());
    ui->plainTextEdit->appendHtml(qsz);
    ui->plainTextEdit->ensureCursorVisible();
*/
}

void UDPdlg::slotCanviaPortRx(QString qsz){
    bool ok;
    disconnect(udpSocketUdpRx);
    udpSocketUdpRx->abort();
    delete udpSocketUdpRx;

    udpSocketUdpRx = new QUdpSocket(this);
    udpSocketUdpRx->bind(qsz.toInt(&ok,10));
    connect(udpSocketUdpRx, SIGNAL(readyRead()),this, SLOT(vDatagramaUdpRxRebut()));
}

void UDPdlg::on_botIntercanvi_clicked(){
    QString qszAux;

    qszAux = ui->lineEditPortRx->text();
    ui->lineEditPortRx->setText(ui->lineEditPortTx->text());
    ui->lineEditPortTx->setText(qszAux);
}
