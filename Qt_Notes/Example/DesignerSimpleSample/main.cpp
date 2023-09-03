#include "DesignerSimpleSample.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DesignerSimpleSample w;
    w.show();
    return a.exec();
}
