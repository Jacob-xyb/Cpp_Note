#pragma once

#include <QMainWindow>
#include "ui_CustomToolbars.h"

class CustomToolbars  : public QMainWindow
{
	Q_OBJECT

public:
	CustomToolbars(QWidget* parent = nullptr);
	~CustomToolbars();

private:
	Ui::CustomToolbars ui;
};
