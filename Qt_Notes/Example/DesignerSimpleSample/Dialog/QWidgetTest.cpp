#include "QWidgetTest.h"

QWidgetTest::QWidgetTest(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::QWidgetTestClass())
{
	ui->setupUi(this);
}

QWidgetTest::~QWidgetTest()
{
	delete ui;
}
