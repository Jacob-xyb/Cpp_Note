#include "TestQTime.h"

void TestQTime::TestQTime_static_currentTime()
{
	qDebug() << QTime::currentTime();
	qDebug() << QTime::currentTime().toString("HH:mm:ss");
}

void TestQDateTime::TestQDateTime_static_currentDateTime()
{
	qDebug() << QDateTime::currentDateTime();
	qDebug() << QDateTime::currentDateTime().toString("yyyyMMddhhmmss");  // 年月日时分秒
}
