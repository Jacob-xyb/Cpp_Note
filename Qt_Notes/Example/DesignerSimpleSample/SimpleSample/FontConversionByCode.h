#pragma once

#include <QDialog>
#include <qcheckbox.h>
#include <qradiobutton.h>
#include <qpushbutton.h>
#include <qplaintextedit.h>
#include <qlayout.h>

class FontConversionByCode : public QDialog
{
	Q_OBJECT

public:
	FontConversionByCode(QWidget* parent = nullptr);
	~FontConversionByCode();

	QCheckBox* cbx_underline;
	QCheckBox* cbx_italic;
	QCheckBox* cbx_bold;
	QRadioButton* rBtn_black;
	QRadioButton* rBtn_red;
	QRadioButton* rBtn_blue;
	QPlainTextEdit* plainTextEdit;
	QVBoxLayout* HLayout_main;
	QHBoxLayout* HLayout1;
	QHBoxLayout* HLayout2;

	void setupUi();
};
