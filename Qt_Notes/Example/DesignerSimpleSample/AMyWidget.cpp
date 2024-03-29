#include "AMyWidget.h"
#include <iostream>

#include "FontConversion.h"
#include "Layout/QSplitterTest.h"
#include "Widget/QTableViewTest.h"
#include "Layout/QSizePolicyTest.h"
#include "Dialog/QMessageBoxTest.h"
#include "Dialog/QDialogTest.h"
#include "Enum/QWindowTypeTest.h"
#include "Widget/QLabelTest.h"
#include "Widget/QLineEditTest.h"
#include "Layout/QButtonGroupTest.h"
#include "SimpleSample/FontConversionByCode.h"

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

void AMyWidget::keyPressEvent(QKeyEvent* event)
{
	//qDebug() << event->text();
	if (event->key() == Qt::Key::Key_R && event->modifiers() == Qt::ControlModifier)
	{
		QString dirname = QApplication::applicationDirPath();
		QString proj_dir = dirname.left(dirname.indexOf("/x64"));

		QFile file(proj_dir + "/Example/DesignerSimpleSample/main.qss");
		file.open(QIODevice::ReadOnly);
		qobject_cast<QApplication*>(QApplication::instance())->setStyleSheet(file.readAll());
		file.close();
	} 
}

void AMyWidget::on_btn_CustomToolbars_clicked()
{
	w->setWindowModality(Qt::WindowModal);
	w->show();
}

void AMyWidget::on_btn_UIDevelopMode_Mixture_clicked()
{
	FontConversion* w = new FontConversion;
	w->exec();
	delete w;
}

void AMyWidget::on_btn_UIDevelopMode_Code_clicked()
{
	FontConversionByCode* w = new FontConversionByCode;
	w->exec();
	delete w;
}

void AMyWidget::on_btn_Splitter_clicked()
{
	QSplitterTest* w = new QSplitterTest;
	w->exec();
	delete w;
}

void AMyWidget::on_btn_TableView_clicked()
{
	QTableViewTest* w = new QTableViewTest;
	w->exec();
	delete w;
}

void AMyWidget::on_btn_SizePolicy_clicked()
{
	QSizePolicyTest* w = new QSizePolicyTest;
	w->exec();
	delete w;
}

void AMyWidget::on_btn_MessageBox_clicked()
{
	QMessageBoxTest* w = new QMessageBoxTest;
	w->setAttribute(Qt::WA_DeleteOnClose);
	w->exec();
	delete w;
}

void AMyWidget::on_btn_QDialog_clicked()
{
	QDialogTest* w = new QDialogTest;
	w->exec();
	delete w;
}

void AMyWidget::on_btn_TreeWidget_clicked()
{
	QTreeWidgetTest* w = new QTreeWidgetTest;
	w->exec();
	delete w;
}

void AMyWidget::on_btn_QWindowType_clicked()
{
	QWindowTypeTest* w = new QWindowTypeTest;
	w->exec();
	delete w;
}

void AMyWidget::on_btn_QLabel_clicked()
{
	QLabelTest* w = new QLabelTest;
	w->exec();
	delete w;
}

void AMyWidget::on_btn_QLineEdit_clicked()
{
	QLineEditTest w;
	w.exec();
}

void AMyWidget::on_btn_QButtonGroup_clicked()
{
	QButtonGroupTest* w = new QButtonGroupTest;
	w->exec();
	delete w;
}

