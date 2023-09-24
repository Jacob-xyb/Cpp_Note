#include "Qt_Basic.h"
#include <QStyleFactory>
#include <qDebug>

Qt_Basic::Qt_Basic(QWidget *parent)
    : QWidget(parent)
{
    //ui.setupUi(this);
    QRadioButton* p = new QRadioButton(this);
    p->move(10, 10);
    p->setText("hello");
    // ≥ı ºªØ
    qobject_cast<QApplication*>(QApplication::instance())->setStyle("windowsvista");
    qDebug() << QStyleFactory::keys();
}

Qt_Basic::~Qt_Basic()
{}
