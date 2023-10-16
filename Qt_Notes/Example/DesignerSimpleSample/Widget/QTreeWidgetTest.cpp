#include "QTreeWidgetTest.h"

QTreeWidgetTest::QTreeWidgetTest(QWidget* parent)
	: QDialog(parent)
	, ui(new Ui::QTreeWidgetTestClass())
{
	ui->setupUi(this);
	tree = ui->treeWidget;
	m_menu = new QMenu(ui->treeWidget);
	m_menu->addAction("open");
	m_menu->addAction("clear");
	connect(m_menu, &QMenu::triggered, this, &QTreeWidgetTest::slotMenuTriggered);

	tree->setContextMenuPolicy(Qt::CustomContextMenu);
	connect(ui->treeWidget, &QTreeWidget::customContextMenuRequested, this, &QTreeWidgetTest::slotMenuPopup);

	//tree->setColumnCount(1);  // 设置列数为 2
	//tree->setHeaderLabels({ "Name", "Value" });  // 设置列标题为 "Name" 和 "Value"
	tree->setHeaderHidden(true);

	// 创建3个根节点
	QTreeWidgetItem* root1 = new QTreeWidgetItem(tree);
	root1->setText(0, "Root1");                            // 设置节点文本
	root1->setText(1, "1");                               // 设置节点文本
	QTreeWidgetItem* root2 = new QTreeWidgetItem(tree);
	root2->setText(0, "Root2");                            // 设置节点文本
	root2->setText(1, "2");                               // 设置节点文本
	QTreeWidgetItem* root3 = new QTreeWidgetItem(tree);
	root3->setText(0, "Root3");                            // 设置节点文本
	root3->setText(1, "3");                               // 设置节点文本

	connect(tree, SIGNAL(itemChanged(QTreeWidgetItem*, int)), this, SLOT(treeItemChanged(QTreeWidgetItem*, int)));
}

QTreeWidgetTest::~QTreeWidgetTest()
{
	delete ui;
}

void QTreeWidgetTest::slotMenuPopup(const QPoint& pos)
{
	m_menu->exec(ui->treeWidget->mapToGlobal(pos));
}

void QTreeWidgetTest::on_btn_PrintSelect_clicked()
{
	for each (QTreeWidgetItem* var in ui->treeWidget->selectedItems())
	{
		qDebug() << var->text(0);
	}
}

void QTreeWidgetTest::slotMenuTriggered(QAction* action)
{
	if (action->text() == "open")
	{
		QString path = QFileDialog::getExistingDirectory();
		QDir dir(path);
		QStringList fileList = dir.entryList(QDir::Files);
		qDebug() << fileList;

		QTreeWidgetItem* tmp = new QTreeWidgetItem(tree);
		tmp->setText(0, dir.dirName());
		tmp->setCheckState(0, Qt::Unchecked);
		for (size_t i = 0; i < fileList.size(); i++)
		{
			QTreeWidgetItem* child = new QTreeWidgetItem(tmp);
			child->setText(0, fileList[i]);
			child->setCheckState(0, Qt::Unchecked);
		}
	}
	else if (action->text() == "clear")
	{
		tree->clear();
	}
}

void QTreeWidgetTest::treeItemChanged(QTreeWidgetItem* item, int column)
{
	QString itemText = item->text(0);
	if (item->checkState(0) == Qt::Checked)
	{
		QTreeWidgetItem* parent = item->parent();
		int cnt = item->childCount();
		if (cnt > 0)
		{
			for (int i = 0; i < cnt; i++)
			{
				item->child(i)->setCheckState(0, Qt::Checked);
			}
		}
		else
		{
			updateParentItem(item);
		}
	}
	else if (item->checkState(0) == Qt::Unchecked)
	{
		int cnt = item->childCount();
		if (cnt > 0)
		{
			for (int i = 0; i < cnt; i++)
			{
				item->child(i)->setCheckState(0, Qt::Unchecked);
			}
		}
		else
		{
			updateParentItem(item);
		}
	}
}

void QTreeWidgetTest::updateParentItem(QTreeWidgetItem* item)
{
	QTreeWidgetItem* parent = item->parent();
	if (parent == NULL)
	{
		return;
	}
	//选中的子节点个数
	int selectedCount = 0;
	int childCount = parent->childCount();
	for (int i = 0; i < childCount; i++)
	{
		QTreeWidgetItem* childItem = parent->child(i);
		if (childItem->checkState(0) == Qt::Checked)
		{
			selectedCount++;
		}
	}
	if (selectedCount <= 0)
	{
		//未选中状态
		parent->setCheckState(0, Qt::Unchecked);
	}
	else if (selectedCount > 0 && selectedCount < childCount)
	{
		//部分选中状态
		parent->setCheckState(0, Qt::PartiallyChecked);
	}
	else if (selectedCount == childCount)
	{
		//选中状态
		parent->setCheckState(0, Qt::Checked);
	}
}