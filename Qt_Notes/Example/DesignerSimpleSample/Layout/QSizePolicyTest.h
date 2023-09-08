#pragma once

#include <QDialog>
#include "ui_QSizePolicyTest.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QSizePolicyTestClass; };
QT_END_NAMESPACE

class QSizePolicyTest : public QDialog
{
	Q_OBJECT

public:
	QSizePolicyTest(QWidget *parent = nullptr);
	~QSizePolicyTest();

private:
	Ui::QSizePolicyTestClass *ui;
};
