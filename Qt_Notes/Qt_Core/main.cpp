#include <QtCore/QCoreApplication>
#include "TestQByteArray.h"
#include "TestQString.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //TestQByteArray::QByteArray_InitDiff();
    TestQString::QString_toFloat();

    return a.exec();
}
