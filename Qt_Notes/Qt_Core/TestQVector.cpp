#include "TestQVector.h"
#include <qobject.h>
#include <qDebug>

void TestQVector::QVector_copy()
{
	std::vector<int> arr = { 1, 2, 3 };
	QVector<int> qvi({ 1, 2, 3 });
	qDebug() << qvi;

	QVector<int> qvi2 = qvi;	// Ç³¿½±´
	qvi2[0] = 99;
	qDebug() << qvi2 << qvi;
}

void TestQVector::QVector_initByStdVector()
{
	std::vector<int> arr = { 1, 2, 3 };
	QVector<int> qvi(arr.begin(), arr.end());

	qDebug() << qvi;

	QVector<int> qvi2 = qvi;	// Ç³¿½±´
	qvi2[0] = 99;
	qDebug() << qvi2 << qvi;
}
