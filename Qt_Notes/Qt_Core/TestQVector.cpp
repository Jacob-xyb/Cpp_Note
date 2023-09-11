#include "TestQVector.h"
#include <qobject.h>
#include <qDebug>

void TestQVector::QVector_copy()
{
	QVector<int> qvi({ 1, 2, 3 });
	qDebug() << qvi;

	QVector<int>qvi2 = qvi;
	qvi2[0] = 99;
	qDebug() << qvi2 << qvi;
}
