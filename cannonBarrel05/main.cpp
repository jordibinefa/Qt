#include <QtGui/QApplication>
#include "cannonbarreldlg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cannonBarrelDlg w;
    w.show();

    return a.exec();
}
