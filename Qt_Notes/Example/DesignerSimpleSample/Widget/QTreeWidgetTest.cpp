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
	connect(ui->treeWidget, &QTreeWidget::customContextMenuRequested,this, &QTreeWidgetTest::slotMenuPopup);
	
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
}

QTreeWidgetTest::~QTreeWidgetTest()
{
	delete ui;
}

void QTreeWidgetTest::slotMenuPopup(const QPoint& pos)
{
	m_menu->exec(ui->treeWidget->mapToGlobal(pos));
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