#pragma once

#include <QDialog>
#include "ui_QWidgetTest.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QWidgetTestClass; };
QT_END_NAMESPACE

class QWidgetTest : public QDialog
{
	Q_OBJECT

public:
	QWidgetTest(QWidget *parent = nullptr);
	~QWidgetTest();

private:
	Ui::QWidgetTestClass *ui;
};
