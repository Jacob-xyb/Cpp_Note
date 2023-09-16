#include <QtCore/QCoreApplication>
#include "TestQByteArray.h"
#include "TestQString.h"
#include "TestQVector.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //TestQByteArray::QByteArray_InitDiff();

    //TestQString::QString_split_QRegExp();

    TestQVector::QVector_copy();
    TestQVector::QVector_initByStdVector();

    return a.exec();
}
