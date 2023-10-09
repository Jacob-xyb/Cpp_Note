#include "QLabelTest.h"

QLabelTest::QLabelTest(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::QLabelTestClass())
{
	ui->setupUi(this);
	_init_ui();
}

QLabelTest::~QLabelTest()
{
	delete ui;
}

void QLabelTest::_init_ui()
{
	_init_lable_elide();
}

void QLabelTest::_init_lable_elide()
{
	QString str = tr("这是一个很长很长的标签");
	QString text = ui->label_elide->fontMetrics().elidedText(str, Qt::ElideRight, 100);
	ui->label_elide->setText(text);
}
