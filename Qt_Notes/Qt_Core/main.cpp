#include <QtCore/QCoreApplication>
#include "TestQByteArray.h"
#include "TestQString.h"
#include "TestQVector.h"
#include "TestQTime.h"
#include "TestFileManagement.h"
#include "TestQRegExp.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //TestQByteArray::QByteArray_InitDiff();

    //TestQString::QString_split_QRegExp();
    //TestQString::QString_replace_QRegExp();
    //TestQString::QString_toFloat();
    //TestQString::QString_sprintf();
    //TestQString::QString_arg();
    //TestQString::QString_delete_space();

    TestQRegExp::QRegExp_exactMatch();

    //TestQVector::QVector_copy();
    //TestQVector::QVector_copy2();
    //TestQVector::QVector_initByStdVector();

    //TestQTime::TestQTime_static_currentTime();

    //TestQDateTime::TestQDateTime_static_currentDateTime();

    //TestQDir::TestQDir_filePath();

    return a.exec();
}
