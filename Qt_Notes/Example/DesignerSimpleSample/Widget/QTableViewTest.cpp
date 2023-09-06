#include "QTableViewTest.h"
#include "qdebug.h"
#pragma execution_character_set("UTF-8")

QTableViewTest::QTableViewTest(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::QTableViewTestClass())
{
	ui->setupUi(this);
	model = new QStandardItemModel;
	ui->tableView->setModel(model);
	initModel();
}

QTableViewTest::~QTableViewTest()
{
	delete ui;
}

void QTableViewTest::initModel()
{
	QStringList table_h_headers;
	table_h_headers << "Name" << "Age" << "Level" << "Id" << "Date";

	model->setHorizontalHeaderLabels(table_h_headers);	
}
