#include "QLineEditTest.h"

QLineEditTest::QLineEditTest(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::QLineEditTestClass())
{
	ui->setupUi(this);
}

QLineEditTest::~QLineEditTest()
{
	delete ui;
}
