#include "QSizePolicyTest.h"
#include "qdebug.h"

QSizePolicyTest::QSizePolicyTest(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::QSizePolicyTestClass())
{
	ui->setupUi(this);
	qDebug() << ui->pushButton->sizeHint();
	qDebug() << ui->pushButton_2->sizeHint();
}

QSizePolicyTest::~QSizePolicyTest()
{
	delete ui;
}
