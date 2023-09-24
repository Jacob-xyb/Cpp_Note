#include "Qt_Basic.h"
#include <QtWidgets/QApplication>  // qt中类名和头文件名一样，而且没有.h
#include "Qt_MetaObject.h"

int main(int argc, char* argv[])
{
	bool isUI = 1;

	QApplication a(argc, argv);

	if (isUI)
	{
		Qt_Basic w;
		w.show();
		return a.exec();
	}
	else
	{
		Qt_MetaObject obj;
		obj.Qt_MetaObject_className();

		return 0;
	}

}
