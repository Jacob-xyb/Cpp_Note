#include "QDialogTest.h"

QDialogTest::QDialogTest(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::QDialogTestClass())
{
	ui->setupUi(this);
	ui->btn_basicDialog->setDefault(true);
}

QDialogTest::~QDialogTest()
{
	delete ui;
}

void QDialogTest::on_btn_structDialog_clicked()
{
	QDialog d(this, Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
	//d.setSizeGripEnabled(true);
	d.exec();
}

void QDialogTest::on_btn_basicDialog_clicked()
{
	QDialog d;
	d.exec();
}