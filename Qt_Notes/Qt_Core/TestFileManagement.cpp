#include "TestFileManagement.h"

void TestQDir::TestQDir_filePath()
{
	QString dir_path = "C:/User/data";
	QDir dir(dir_path);
	qDebug() << dir.filePath("context.txt");
}
