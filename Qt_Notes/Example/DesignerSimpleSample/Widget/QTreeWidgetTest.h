#pragma once

#include <QDialog>
#include "ui_QTreeWidgetTest.h"
#include <QMenu>
#include <QFileDialog>
#include <qDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class QTreeWidgetTestClass; };
QT_END_NAMESPACE

class QTreeWidgetTest : public QDialog
{
	Q_OBJECT

public:
	QTreeWidgetTest(QWidget *parent = nullptr);
	~QTreeWidgetTest();


public slots:
	void slotMenuTriggered(QAction* action);
	void slotMenuPopup(const QPoint& pos);

private:
	Ui::QTreeWidgetTestClass *ui;
	QTreeWidget* tree;
	QMenu* m_menu;
};
