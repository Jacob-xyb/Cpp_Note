#pragma once
#include <QDialog>
#include "ui_QMessageBoxTest.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QMessageBoxTestClass; };
QT_END_NAMESPACE

class QMessageBoxTest : public QDialog
{
	Q_OBJECT

public:
	QMessageBoxTest(QWidget* parent = nullptr);
	~QMessageBoxTest();
	void initUI();

public slots:
	void on_btn_generate_clicked();

private:
	Ui::QMessageBoxTestClass* ui;
};