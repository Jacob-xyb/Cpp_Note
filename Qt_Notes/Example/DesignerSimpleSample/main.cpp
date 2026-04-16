#include <QtWidgets/QApplication>
#include "AMyWidget.h"
#include "CustomToolbars.h"
#include "Dialog/QSSDebugWidget.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    AMyWidget w;
    w.show();

    QSSDebugWidget debugWidget;
    debugWidget.show();

    return a.exec();
}
