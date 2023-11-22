#include "QButtonGroupTest.h"

QButtonGroupTest::QButtonGroupTest(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::QButtonGroupTestClass())
{
	ui->setupUi(this);
	m_group = new QButtonGroup;
	m_group->addButton(ui->radioButton_1, 0);
	m_group->addButton(ui->radioButton_2, 1);
	m_group->addButton(ui->radioButton_3, 2);
	connect(m_group, &QButtonGroup::idClicked, this, &QButtonGroupTest::slot_buttonClicked);
}

QButtonGroupTest::~QButtonGroupTest()
{
	delete ui;
}

void QButtonGroupTest::slot_buttonClicked(int index)
{
	m_group->button(index)->hide();
}
