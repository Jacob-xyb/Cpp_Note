#include <QtCore/QCoreApplication>
#include "TestQByteArray.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TestQByteArray::QByteArray_InitDiff();

    return a.exec();
}
