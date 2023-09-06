#pragma once

#include <QDialog>
#include "ui_QTableViewTest.h"
#include <qstandarditemmodel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class QTableViewTestClass; };
QT_END_NAMESPACE

class QTableViewTest : public QDialog
{
	Q_OBJECT

public:
	QTableViewTest(QWidget *parent = nullptr);
	~QTableViewTest();
	void initModel();

private:
	Ui::QTableViewTestClass *ui;
	QStandardItemModel* model;
};
