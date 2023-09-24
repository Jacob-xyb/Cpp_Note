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
	qDebug() << s1.split(QRegExp("[\\s,]"), Qt::SplitBehaviorFlags::SkipEmptyParts);	// \\s 代表所有空格，回车，换行等
}

void TestQString::QString_replace_QRegExp()
{
	//正则表达式
	QString s1 = "<font color=red>hhhh</font>eeee";
	qDebug() << s1.replace(QRegExp("<[^>]*>"), "");	// \\s 代表所有空格，回车，换行等
}

void TestQString::QString_toFloat()
{
	QString s1 = "123a";	// "123a" 不能转 float
	bool flag = false;
	float f1 = s1.toFloat(&flag);
	if (flag)
	{
		qDebug() << "successfully" << f1;
	}
	else
	{
		qDebug() << "failed" << f1;
	}
}
