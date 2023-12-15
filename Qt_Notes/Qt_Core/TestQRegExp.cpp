#include "TestQRegExp.h"
#include <qstringlist.h>
#include <qdebug.h>

void TestQRegExp::QRegExp_exactMatch()
{
	QRegExp reg(".*xy\\d+");
	QStringList lists = { "xy", "xy1", "xy2", "xy3", "1#xy",  "2#xy2", "2#xy23"};

	for each (QString var in lists)
	{
		if (reg.exactMatch(var))
		{
			qDebug() << var;
		}
	}

}
