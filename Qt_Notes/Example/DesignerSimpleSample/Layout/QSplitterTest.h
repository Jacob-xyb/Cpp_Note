#pragma once

#include <QWidget>
#include "ui_QSplitterTest.h"
#include <qsplitter.h>

QT_BEGIN_NAMESPACE
namespace Ui { class QSplitterTest; };
QT_END_NAMESPACE

class QSplitterTest : public QDialog
{
	Q_OBJECT

public:
	QSplitterTest(QWidget *parent = nullptr);
	~QSplitterTest();
	void initUI();

private:
	Ui::QSplitterTest *ui;
	//QSplitter* splitterMain;
	//QWidget* w_green;
	//QWidget* w_red;
	//QWidget* w_blue;
	//QWidget* w_white;
};
