#include "ginyudprxtx.h"
#include "ui_ginyudprxtx.h"

GinyUdpRxTx::GinyUdpRxTx(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GinyUdpRxTx)
{
    ui->setupUi(this);

    gUdpTx = new GinyUdpTramet;
    gUdpRx = new GinyUDP;
    ui->verticalLayoutTx->addWidget(gUdpTx);
    ui->verticalLayoutRx->addWidget(gUdpRx);
    connect(gUdpTx,SIGNAL(vTrametRxUdpPort(int)),gUdpRx,SLOT(vCanviaPort(int)));
}

GinyUdpRxTx::~GinyUdpRxTx()
{
    delete ui;
}
