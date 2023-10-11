#include "QCustomPlotTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCustomPlotTest w;
    w.show();
    return a.exec();
}
