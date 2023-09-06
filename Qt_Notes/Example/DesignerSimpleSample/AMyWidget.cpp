#include "AMyWidget.h"
#include <iostream>

#include "FontConversion.h"
#include "Layout/QSplitterTest.h"

using namespace std;

AMyWidget::AMyWidget(QWidget* parent)
{
	ui.setupUi(this);
	initSignalSlots();
}

AMyWidget::~AMyWidget()
{
}

void AMyWidget::initSignalSlots()
{

}

void AMyWidget::on_btn_CustomToolbars_clicked()
{
	w->setWindowModality(Qt::WindowModal);
	w->show();
}

void AMyWidget::on_btn_FontConversion_clicked()
{
	FontConversion* w = new FontConversion;
	w->exec();
	delete w;
}

void AMyWidget::on_btn_Splitter_clicked()
{
	QSplitterTest* w = new QSplitterTest;
	w->exec();
	delete w;
}

