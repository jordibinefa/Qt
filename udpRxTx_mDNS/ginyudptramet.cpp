#include "ginyudptramet.h"
#include "ui_ginyudptramet.h"

#include <QDebug>
#include <QUdpSocket>
#include <QHostAddress>
#include <QTimer>
#include <QHostInfo>

#include <qMDNS.h>

GinyUdpTramet::GinyUdpTramet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GinyUdpTramet)
{
    ui->setupUi(this);
    ui->leText->selectAll();
    ui->leText->setFocus();
    ui->lbInfo->setText(" ");
    ui->leDN->setDisabled(true);

    // Aquest sistema de trobar la IP del dispositiu mDNS ens obliga a repensar bSendUdpByteArray
    // En comptes de retornar un booleà haurem de fer un sistema de senyals/slots i, per tant,
    // afegir alguna mena de timeout
    m_mDNS = qMDNS::getInstance();
    connect(m_mDNS,  &qMDNS::hostFound,
            this,    &GinyUdpTramet::vShow_mDNS_IP);
}

GinyUdpTramet::~GinyUdpTramet()
{
    delete ui;
}

void GinyUdpTramet::on_btSend_clicked()
{
    //qDebug() << ui->leText->text();
    vSendUdpDatagram();
}

QStringList GinyUdpTramet::qslDNSResolver(QString host){
    // Aquest mètode no funciona a Android.
    // Android no resol el protocol mDNS per disseny.
    // Per això fem servir la biblioteca qMDNS com a alternativa.
    QHostInfo hostInfo;
    QHostInfo returnedHost = hostInfo.fromName(host);
    QStringList list;

    if (returnedHost.error() != QHostInfo::NoError) {
         qDebug() << "Lookup failed:" << returnedHost.errorString();
    }else
        foreach (const QHostAddress &address, returnedHost.addresses())
        {
              list<<address.toString();
        }

    return list;
}

void GinyUdpTramet::vShow_mDNS_IP(const QHostInfo& info){
    // De vegades falla. Al ser UDP no sempre resol el mDNS a l'instant. Si passa, hauria de reintentar-ho més cops.
    qDebug() << info.hostName().toStdString().c_str() << " : " << info.addresses().first();
    QString qszHostName(info.hostName().toStdString().c_str());
    QHostAddress qhaHostName(info.addresses().first());
    if(qszHostName == ui->leDN->text()){
        ui->leIP->setText(qhaHostName.toString()); // Actualitzo el valor de la IP. No cal.
        QUdpSocket *udpSendingSocket = new QUdpSocket(this);
        vShowIfUdpHasBeenSent(m_bSent=udpSendingSocket->writeDatagram(m_qbaLast,qhaHostName,ui->lePort->text().toInt()));
    }
}

bool GinyUdpTramet::bSendUdpByteArray(QByteArray qba){
    QUdpSocket *udpSendingSocket = new QUdpSocket(this);
    bool bSuccessfullySent = false;

    if (ui->radioButtonBroadcast->isChecked()){
        bSuccessfullySent = udpSendingSocket->writeDatagram(qba,QHostAddress::Broadcast,ui->lePort->text().toInt());
    }

    if(ui->radioButtonSingle->isChecked())
        bSuccessfullySent = udpSendingSocket->writeDatagram(qba,QHostAddress(ui->leIP->text()),ui->lePort->text().toInt());
        //bSuccessfullySent = udpSendingSocket->writeDatagram(qba,QHostAddress("esp8266-dam-00.local"),ui->lePort->text().toInt());

    if(ui->radioButtonSingleDN->isChecked()){
        QString qsz = ui->leDN->text();
        qMDNS::getInstance()->lookup (qsz);
        qDebug() << "DN: " << qsz;
//        QStringList qsl(qslDNSResolver(qsz));
//        QHostAddress qha(qsz);

//        qDebug() << QString::number(qsl.length());

//        if(qsl.length())
//            for ( const auto& i : qsl  ){
//                qha.setAddress(i);
//                if(i.contains(".")){
//                    qDebug() << qha.toString();
//                    bSuccessfullySent = udpSendingSocket->writeDatagram(qba,qha,ui->lePort->text().toInt());
//                    break;
//                }
//            }
    }
    if(bSuccessfullySent){
        //ui->lbInfo->setStyleSheet("QLabel { background-color : green; color : blue; }");
        ui->lbInfo->setStyleSheet("QLabel { color : green; }");
        ui->lbInfo->setText("UDP successfully sent");
    }else{
        //ui->lbInfo->setStyleSheet("QLabel { background-color : red; color : blue; }");
        ui->lbInfo->setStyleSheet("QLabel { color : red; }");
        ui->lbInfo->setText("UDP has not been sent");
    }
    QTimer::singleShot(1000, this, SLOT(vRemoveInfo()));
    return bSuccessfullySent;
}

void GinyUdpTramet::vShowIfUdpHasBeenSent(bool bSuccessfullySent){
    if(bSuccessfullySent){
        ui->lbInfo->setStyleSheet("QLabel { color : green; }");
        ui->lbInfo->setText("UDP successfully sent");
    }else{
        ui->lbInfo->setStyleSheet("QLabel { color : red; }");
        ui->lbInfo->setText("UDP has not been sent");
    }
    QTimer::singleShot(1000, this, SLOT(vRemoveInfo()));
}

void GinyUdpTramet::vSendUdpByteArray(QByteArray qba){
    QUdpSocket *udpSendingSocket = new QUdpSocket(this);
    m_qbaLast = qba; // Per a recordar que he d'enviar si es fa servir mDNS

    if (ui->radioButtonBroadcast->isChecked()){
        vShowIfUdpHasBeenSent(m_bSent=udpSendingSocket->writeDatagram(qba,QHostAddress::Broadcast,ui->lePort->text().toInt()));
    }

    if(ui->radioButtonSingle->isChecked())
        vShowIfUdpHasBeenSent(m_bSent=udpSendingSocket->writeDatagram(qba,QHostAddress(ui->leIP->text()),ui->lePort->text().toInt()));

    if(ui->radioButtonSingleDN->isChecked()){
//        QString qsz = ui->leDN->text();
//        qMDNS::getInstance()->lookup (qsz);
//        qDebug() << "DN: " << qsz;
        vLookForIpFrom_mDNS_andSend(ui->leDN->text());
    }
}

void GinyUdpTramet::vLookForIpFrom_mDNS_andSend(QString mDnsName){
    m_bSent = false;
    qMDNS::getInstance()->lookup (mDnsName);
    // si es resol l'mDNS es crida a l'slot vShow_mDNS_IP
    QTimer::singleShot(250, this, SLOT(vShowTimeOut()));
}

void GinyUdpTramet::vRemoveInfo(){
    ui->lbInfo->setText(" ");
}

void GinyUdpTramet::vShowTimeOut(){
    if(!m_bSent){
        ui->lbInfo->setStyleSheet("QLabel { color : red; }");
        ui->lbInfo->setText("Timeout !");

        QTimer::singleShot(1000, this, SLOT(vRemoveInfo()));
    }
}

void GinyUdpTramet::on_lePort_textChanged(const QString &arg1){
    emit vTrametRxUdpPort(arg1.toInt()-1); // PortRx = PortTx-1 in this device
}

void GinyUdpTramet::vSendUdpDatagram(){
    //bSendUdpByteArray(ui->leText->text().toLatin1());
    vSendUdpByteArray(ui->leText->text().toLatin1());
}

void GinyUdpTramet::on_cbR_clicked(bool checked){
    //bSendUdpByteArray(checked?"15H":"15L");
    vSendUdpByteArray(checked?"15H":"15L");
}

void GinyUdpTramet::on_cbG_clicked(bool checked){
    //bSendUdpByteArray(checked?"13H":"13L");
    vSendUdpByteArray(checked?"13H":"13L");
}

void GinyUdpTramet::on_cbB_clicked(bool checked){
    //bSendUdpByteArray(checked?"12H":"12L");
    vSendUdpByteArray(checked?"12H":"12L");
}

void GinyUdpTramet::on_cbLittleB_clicked(bool checked){
    //bSendUdpByteArray(checked?"2L":"2H");
    vSendUdpByteArray(checked?"2L":"2H");
}
