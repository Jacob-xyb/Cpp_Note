#include "Qt_Basic.h"
#include <QtWidgets/QApplication>  // qt中类名和头文件名一样，而且没有.h

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_Basic w;
    w.show();
    return a.exec();
}
