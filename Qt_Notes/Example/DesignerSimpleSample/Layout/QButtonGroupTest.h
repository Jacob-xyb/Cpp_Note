#pragma once

#include <QDialog>
#include "ui_QButtonGroupTest.h"
#include <QButtonGroup>
#include <qabstractbutton.h>

QT_BEGIN_NAMESPACE
namespace Ui { class QButtonGroupTestClass; };
QT_END_NAMESPACE

class QButtonGroupTest : public QDialog
{
	Q_OBJECT

public:
	QButtonGroupTest(QWidget *parent = nullptr);
	~QButtonGroupTest();

public slots:
	void slot_buttonClicked(int index);

private:
	Ui::QButtonGroupTestClass *ui;
	QButtonGroup* m_group;
};
