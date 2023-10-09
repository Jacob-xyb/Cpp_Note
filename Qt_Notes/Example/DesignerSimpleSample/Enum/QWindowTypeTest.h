#pragma once

#include <QDialog>
#include "ui_QWindowTypeTest.h"
#include <QMetaEnum>

#pragma execution_character_set("UTF-8")

QT_BEGIN_NAMESPACE
namespace Ui { class QWindowTypeTestClass; };
QT_END_NAMESPACE

class QWindowTypeTest : public QDialog
{
	Q_OBJECT

public:
	QWindowTypeTest(QWidget *parent = nullptr);
	~QWindowTypeTest();

private:
	Ui::QWindowTypeTestClass *ui;

	void _init_ui();

private slots:
	void on_pushButton_clicked();
};
