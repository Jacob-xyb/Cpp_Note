#include "Qt_MainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qt_MainWindow w;
    w.show();
    return a.exec();
}
