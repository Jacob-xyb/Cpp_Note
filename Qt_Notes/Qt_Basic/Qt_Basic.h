#pragma once

#include <QtWidgets/QWidget>
#include "ui_Qt_Basic.h"
#include <qpushbutton.h>

class Qt_Basic : public QWidget
{
	Q_OBJECT

public:
	Qt_Basic(QWidget* parent = nullptr);
	~Qt_Basic();

private:
	Ui::Qt_BasicClass ui;
};
