#include <QtGui/QApplication>
#include "udplcdrangedlg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    udpLcdRangeDlg w;
    w.show();

    return a.exec();
}
