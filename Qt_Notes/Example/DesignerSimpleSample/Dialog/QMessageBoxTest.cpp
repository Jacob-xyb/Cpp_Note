#include "QMessageBoxTest.h"
#include <qmessagebox.h>
#include <qDebug>
#pragma execution_character_set("UTF-8")

QMessageBoxTest::QMessageBoxTest(QWidget* parent) : QDialog(parent), ui(new Ui::QMessageBoxTestClass())
{
	ui->setupUi(this);
	initUI();
}

QMessageBoxTest::~QMessageBoxTest()
{
}

void QMessageBoxTest::initUI()
{
	ui->comboBox->addItem("about");
	ui->comboBox->addItem("aboutQt");
	ui->comboBox->addItem("question");
}

void QMessageBoxTest::on_btn_generate_clicked()
{
	QString type = ui->comboBox->currentText();
	QString title = ui->lineEdit_title->text();
	QString text = ui->lineEdit_text->text();
	if (type == "about") QMessageBox::about(this, title, text);
	else if (type == "aboutQt") QMessageBox::aboutQt(this, text);
	else if (type == "question")
	{
		int ret = QMessageBox::question(this, title, text);
		switch (ret)
		{
		case QMessageBox::Yes:
			qDebug() << "选择了yes";
			break;
		case QMessageBox::No:
			qDebug() << "选择了no";
			break;
		default:
			break;
		}
	}
}
