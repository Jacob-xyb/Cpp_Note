#pragma once

#include <QDialog>
#include "ui_QTableViewTest.h"
#include <qstandarditemmodel.h>
#include "qstyleditemdelegate.h"
#include "qcheckbox.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QTableViewTestClass; };
QT_END_NAMESPACE

class CheckboxDelegate : public QStyledItemDelegate
{
	Q_OBJECT
public:
	CheckboxDelegate(QObject* parent = nullptr);
	virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option,
		const QModelIndex& index) const override;

	void setEditorData(QWidget* editor, const QModelIndex& index) const override;
	void setModelData(QWidget* editor, QAbstractItemModel* model,
		const QModelIndex& index) const override;
	void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option,
		const QModelIndex& index) const override;
	virtual void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;

	virtual bool editorEvent(QEvent* event, QAbstractItemModel* model, const QStyleOptionViewItem& option, const QModelIndex& index);

private:

};

class QTableViewTest : public QDialog
{
	Q_OBJECT

public:
	QTableViewTest(QWidget *parent = nullptr);
	~QTableViewTest();
	void initModel();

private:
	Ui::QTableViewTestClass *ui;
	QStandardItemModel* model;
};
