#include "TestQString.h"
#include <QString>
#include <qDebug>
#include <QRegExp>

void TestQString::QString_split()
{
	//基础用法
	QString s1 = "hello sworld";
	qDebug() << s1.split(" ");


}

void TestQString::QString_split_QRegExp()
{
	//正则表达式
	QString s1 = "12.1, 2141.1, 41.6, 41.9";
	qDebug() << s1.split(QRegExp("\\s"));	// \\s 代表所有空格，回车，换行等
	qDebug() << s1.split(QRegExp("[\\s\,]"), Qt::SplitBehaviorFlags::SkipEmptyParts);	// \\s 代表所有空格，回车，换行等
}
