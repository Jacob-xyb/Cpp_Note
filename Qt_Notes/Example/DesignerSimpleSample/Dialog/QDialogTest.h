#pragma once

#include <QDialog>
#include "ui_QDialogTest.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QDialogTestClass; };
QT_END_NAMESPACE

class QDialogTest : public QDialog
{
	Q_OBJECT

public:
	QDialogTest(QWidget *parent = nullptr);
	~QDialogTest();
	
public slots:
	void on_btn_basicDialog_clicked();
	void on_btn_structDialog_clicked();

private:
	Ui::QDialogTestClass *ui;
};
