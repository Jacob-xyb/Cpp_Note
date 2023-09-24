#include <QtWidgets/QApplication>
#include "AMyWidget.h"
#include "CustomToolbars.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    AMyWidget w;
    w.show();

    //CustomToolbars w2 = new CustomToolbars;
    //w2.show();
    return a.exec();
}
