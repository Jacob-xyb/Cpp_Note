#pragma once

#include <QDialog>
#include "ui_QLabelTest.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QLabelTestClass; };
QT_END_NAMESPACE

#pragma execution_character_set("UTF-8")

class QLabelTest : public QDialog
{
	Q_OBJECT

public:
	QLabelTest(QWidget *parent = nullptr);
	~QLabelTest();

private:
	Ui::QLabelTestClass *ui;

	void _init_ui();
	void _init_lable_elide();
};
