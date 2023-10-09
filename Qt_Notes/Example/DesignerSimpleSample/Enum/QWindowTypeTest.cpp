#include "QWindowTypeTest.h"

QWindowTypeTest::QWindowTypeTest(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::QWindowTypeTestClass())
{
	ui->setupUi(this);

	_init_ui();
}

QWindowTypeTest::~QWindowTypeTest()
{
	delete ui;
}

void QWindowTypeTest::_init_ui()
{
	ui->textEdit->setText(tr("窗口样式展示"));

	QMetaEnum m = QMetaEnum::fromType<Qt::WindowFlags>();
	for (int i = 0; i < m.keyCount(); i++)
	{
		ui->comboBox->addItem(m.key(i));
	}
}

void QWindowTypeTest::on_pushButton_clicked()
{
	QMetaEnum m = QMetaEnum::fromType<Qt::WindowFlags>();

	QDialog w;
	QLabel* l = new QLabel(&w);
	l->setText(ui->textEdit->toPlainText());
	w.setWindowFlag((Qt::WindowType)m.value(ui->comboBox->currentIndex()));
	w.exec();
}


