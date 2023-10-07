#include <QtCore/QCoreApplication>
#include "TestQByteArray.h"
#include "TestQString.h"
#include "TestQVector.h"
#include "TestQTime.h"
#include "TestFileManagement.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //TestQByteArray::QByteArray_InitDiff();

    //TestQString::QString_split_QRegExp();
    //TestQString::QString_replace_QRegExp();
    //TestQString::QString_toFloat();

    //TestQVector::QVector_copy();
    //TestQVector::QVector_copy2();
    //TestQVector::QVector_initByStdVector();

    //TestQTime::TestQTime_static_currentTime();

    //TestQDateTime::TestQDateTime_static_currentDateTime();

    TestQDir::TestQDir_filePath();

    return a.exec();
}
