#include <QtCore/QCoreApplication>
#include "TestQByteArray.h"
#include "TestQString.h"
#include "TestQVector.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //TestQByteArray::QByteArray_InitDiff();

    //TestQString::QString_split_QRegExp();
    //TestQString::QString_replace_QRegExp();
    //TestQString::QString_toFloat();

    //TestQVector::QVector_copy();
    TestQVector::QVector_copy2();
    //TestQVector::QVector_initByStdVector();

    return a.exec();
}
