#pragma once

#include <QDialog>
#include "ui_QLineEditTest.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QLineEditTestClass; };
QT_END_NAMESPACE

class QLineEditTest : public QDialog
{
	Q_OBJECT

public:
	QLineEditTest(QWidget *parent = nullptr);
	~QLineEditTest();

private:
	Ui::QLineEditTestClass *ui;
};
