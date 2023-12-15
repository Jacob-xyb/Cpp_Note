#include "FontConversionByCode.h"

FontConversionByCode::FontConversionByCode(QWidget *parent)
	: QDialog(parent)
{
	setupUi();
}

FontConversionByCode::~FontConversionByCode()
{}

void FontConversionByCode::setupUi()
{
	HLayout_main = new QVBoxLayout(this);

	cbx_underline = new QCheckBox(this);
	cbx_underline->setText("Undeline");
	cbx_italic = new QCheckBox(this);
	cbx_italic->setText("Italic");
	cbx_bold = new QCheckBox(this);
	cbx_bold->setText("Bold");
	HLayout1 = new QHBoxLayout;
	HLayout1->addWidget(cbx_underline);
	HLayout1->addWidget(cbx_italic);
	HLayout1->addWidget(cbx_bold);

	rBtn_black = new QRadioButton(this);
	rBtn_black->setText("Black");
	rBtn_blue = new QRadioButton(this);
	rBtn_blue->setText("Blue");
	rBtn_red = new QRadioButton(this);
	rBtn_red->setText("Red");
	HLayout2 = new QHBoxLayout;
	HLayout2->addWidget(rBtn_black);
	HLayout2->addWidget(rBtn_blue);
	HLayout2->addWidget(rBtn_red);

	plainTextEdit = new QPlainTextEdit(this);
	QFont font = plainTextEdit->font();
	font.setPointSize(20);
	plainTextEdit->setFont(font);
	plainTextEdit->setPlainText("Hello World!\nThis is Jacob-xyb.");

	HLayout_main->addLayout(HLayout1);
	HLayout_main->addLayout(HLayout2);
	HLayout_main->addWidget(plainTextEdit);
}
