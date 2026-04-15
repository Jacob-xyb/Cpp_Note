#include "QTreeViewTest.h"
#include <qdebug.h>
#pragma execution_character_set("UTF-8")

QTreeViewTest::QTreeViewTest(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::QTreeViewTestClass())
{
	ui->setupUi(this);
	initTreeView();
	initConnection();
}

QTreeViewTest::~QTreeViewTest()
{
	delete ui;
}

void QTreeViewTest::on_treeView_doubleClicked(const QModelIndex& index)
{
	qInfo() << "你点击了：" + index.data().toString();

	// 判断是否是第二级节点
	// 没有父节点，说明是第一级节点；有父节点，说明是第二级节点
	if (index.parent().isValid())
	{
		// 判断是第几个子节点
		int row = index.row();
		qInfo() << "你点击的是第" << row + 1 << "个子节点";
	}

}

void QTreeViewTest::initTreeView()
{
	// 创建模型
	QStandardItemModel* model = new QStandardItemModel(this);

	// 添加数据
	QStandardItem* rootItem = model->invisibleRootItem();

	// 第一级节点
	QStandardItem* item1 = new QStandardItem("一级节点1");
	QStandardItem* item2 = new QStandardItem("一级节点2");
	rootItem->appendRow(item1);
	rootItem->appendRow(item2);

	// 第二级节点
	QStandardItem* item11 = new QStandardItem("二级节点1-1");
	QStandardItem* item12 = new QStandardItem("二级节点1-2");
	item1->appendRow(item11);
	item1->appendRow(item12);

	QStandardItem* item21 = new QStandardItem("二级节点2-1");
	item2->appendRow(item21);

	ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->treeView->setModel(model);
	ui->treeView->expandAll(); // 展开所有节点
}

void QTreeViewTest::initConnection()
{
	//connect(ui->treeView, &QTreeView::doubleClicked, this, &QTreeViewTest::on_treeView_doubleClicked);
}

void QTreeViewTest::on_btn_testCrash1_clicked()
{
	QTreeView* _treeView = new QTreeView();
	QStandardItemModel* model = new QStandardItemModel(_treeView);
	QPointer<QStandardItemModel> guardedObj = model;
	_treeView->setModel(model);
	delete _treeView;
	// model != nullptr 是错误的
	if (!guardedObj.isNull())
	{
		std::cout << model->rowCount() << std::endl;
		delete model;
	}
	else
	{
		std::cout << "model is nullptr" << std::endl;
	}
}
