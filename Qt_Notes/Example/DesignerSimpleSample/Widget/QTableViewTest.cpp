#include "QTableViewTest.h"
#include "qdebug.h"
#pragma execution_character_set("UTF-8")

CheckboxDelegate::CheckboxDelegate(QObject* parent) : QStyledItemDelegate(parent)
{
}

QWidget* CheckboxDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	qDebug() << "createEditor";
	QCheckBox* cbx = new QCheckBox(parent);
	return cbx;
}

void CheckboxDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
	qDebug() << "setEditorData";
	bool value = index.model()->data(index, Qt::EditRole).toBool();
	QCheckBox* cbx = static_cast<QCheckBox*>(editor);
	if (value) cbx->setCheckState(Qt::Checked);
	else cbx->setCheckState(Qt::Unchecked);
}

void CheckboxDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
	qDebug() << "setModelData";

	QCheckBox* cbx = static_cast<QCheckBox*>(editor);
	//cbx->interpretText();
	int value = cbx->isChecked();

	model->setData(index, value, Qt::EditRole);
}

void CheckboxDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	qDebug() << "updateEditorGeometry";

	editor->setGeometry(option.rect);
}

void CheckboxDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	//qDebug() << "paint";

	if (index.column() == 2)
	{
		bool value = index.data(Qt::UserRole).toInt();
		QStyleOptionButton checkBoxOption;
		QRect checkBoxRect = QApplication::style()->subElementRect(QStyle::SE_CheckBoxIndicator, &checkBoxOption);
		checkBoxOption.rect = option.rect;
		checkBoxOption.rect.setLeft(option.rect.left() + (option.rect.width() - checkBoxRect.width()) / 2);
		checkBoxRect.setTop(option.rect.top() + (option.rect.height() - checkBoxRect.height()) / 2);
		checkBoxOption.state = value ? QStyle::State_On : QStyle::State_Off;
		checkBoxOption.state |= QStyle::State_Enabled;
		QApplication::style()->drawControl(QStyle::CE_CheckBox, &checkBoxOption, painter);

		qDebug() << "option.rect" << option.rect << "checkBoxRect" << checkBoxRect;
		qDebug() << checkBoxOption.rect;
	}//if
	else
	{
		QStyledItemDelegate::paint(painter, option, index);
	}
}

bool CheckboxDelegate::editorEvent(QEvent* event, QAbstractItemModel* model, const QStyleOptionViewItem& option, const QModelIndex& index)
{
	if (event->type() == QEvent::MouseButtonDblClick)//½ûÖ¹Ë«»÷±à¼­
		return true;
	//¹ýÂËÊó±êËÉ¿ª
	if (event->type() == QEvent::MouseButtonRelease) {
		return false;
	}

	bool checked = index.data(Qt::UserRole).toBool();
	model->setData(index, !checked, Qt::UserRole);

	return QStyledItemDelegate::editorEvent(event, model, option, index);
}

QTableViewTest::QTableViewTest(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::QTableViewTestClass())
{
	ui->setupUi(this);
	this->resize(800, 600);
	model = new QStandardItemModel;
	ui->tableView->setModel(model);
	initModel();
}

QTableViewTest::~QTableViewTest()
{
	delete ui;
}

void QTableViewTest::initModel()
{
	QStringList table_h_headers;
	table_h_headers << "Name" << "Age" << "Select" << "Id" << "Date";
	model->setHorizontalHeaderLabels(table_h_headers);	

	model->setItem(0, 0, new QStandardItem("zhangsan"));
	model->setItem(0, 1, new QStandardItem("18"));
	QStandardItem* item = new QStandardItem;
	item->setData(true, Qt::UserRole);
	model->setItem(0, 2, item);
	model->setItem(0, 3, new QStandardItem("1"));

	CheckboxDelegate* delegate = new CheckboxDelegate;
	ui->tableView->setItemDelegateForColumn(2, delegate);
}


