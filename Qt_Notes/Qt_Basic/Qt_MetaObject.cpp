#include "Qt_MetaObject.h"
#include <QtWidgets/QWidget>
#include <qpushbutton.h>
#include <iostream>

using namespace std;

void Qt_MetaObject::Qt_MetaObject_className()
{
	QObject* obj = new QPushButton;
	const QMetaObject* metaObj = obj->metaObject();
	cout << "obj's className:" << metaObj->className() << endl;
}
