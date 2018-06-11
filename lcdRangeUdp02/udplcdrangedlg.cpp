#include "udplcdrangedlg.h"
#include "ui_udplcdrangedlg.h"

udpLcdRangeDlg::udpLcdRangeDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::udpLcdRangeDlg)
{
    ui->setupUi(this);
    lcdR = new LCDRange;
    ui->verticalLayout->addWidget(lcdR);
    connect(lcdR,SIGNAL(valueChanged(int)),this,SLOT(vSendUdp(int)));
    qha = QHostAddress("127.0.0.1");
    nPort = 33333;
    ui->lineEditIP->setText(qha.toString());
    ui->lineEditPort->setText(QString::number(nPort));
}

udpLcdRangeDlg::~udpLcdRangeDlg()
{
    delete ui;
}

void udpLcdRangeDlg::vTrametSocolUdp(QByteArray datagram,QHostAddress adreca,quint16 port){
    QUdpSocket *udpSocketTX = new QUdpSocket(this);
    udpSocketTX->writeDatagram(datagram.data(),datagram.size(),adreca,port);
    delete udpSocketTX;
}

void udpLcdRangeDlg::vSendUdp(int n){
    bool ok;
    int nN = ui->lineEditPort->text().toInt(&ok,10);
    if(ok){
        nPort = nN;
        vTrametSocolUdp(QString::number(n).toAscii(),
                        QHostAddress(ui->lineEditIP->text()),nPort);
    }
}
