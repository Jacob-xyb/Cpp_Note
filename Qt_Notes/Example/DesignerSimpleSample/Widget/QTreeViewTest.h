#pragma once

#include <QDialog>
#include "ui_QTreeViewTest.h"
#include <qstandarditemmodel.h>
#include <iostream>
#include <QPointer> 

QT_BEGIN_NAMESPACE
namespace Ui { class QTreeViewTestClass; };
QT_END_NAMESPACE

class QTreeViewTest : public QDialog
{
	Q_OBJECT

public:
	QTreeViewTest(QWidget *parent = nullptr);
	~QTreeViewTest();

public slots:
	/// <summary>
	/// 测试 QStandardModel 的内存泄漏问题
	/// </summary>
	void on_btn_testCrash1_clicked();

	/// <summary>
	/// 匿名槽函数
	/// </summary>
	/// <param name="index"></param>
	void on_treeView_doubleClicked(const QModelIndex& index);

private:
	Ui::QTreeViewTestClass *ui;

	/// <summary>
	/// 初始化TreeView
	/// </summary>
	void initTreeView();

	void initConnection();
};
