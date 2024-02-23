#include "Qt_MainWindow.h"
#include <QSplitter>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>
#include <qlabel.h>
#include <QToolBar>
#include <qmessagebox.h>

#pragma execution_character_set("UTF-8")

Qt_MainWindow::Qt_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Qt_MainWindowClass())
{
    ui->setupUi(this);

    // 菜单栏
    QMenuBar* mBar = menuBar();
    // 添加菜单
    QMenu* pFile = mBar->addMenu("文件");
    // 菜单中添加动作
    QAction* actNew = pFile->addAction("新建");
    pFile->addSeparator();
    QAction* actOpen = pFile->addAction("打开");

    // 工具栏
    // 使用之前需要先创建一个 toolBar
    QToolBar* toolBar = addToolBar("toolBar");
    // 添加动作的快捷方式
    toolBar->addAction(actNew);

    // 状态栏
    QStatusBar* mstatusBar = statusBar();
    QLabel* lablel = new QLabel(this);
    lablel->setText("This is normal text label");
    mstatusBar->addWidget(lablel);

    show_messagebox();
}

Qt_MainWindow::~Qt_MainWindow()
{
    delete ui;
}

void Qt_MainWindow::show_messagebox()
{
    QMenuBar* mBar = menuBar();
    QMenu* pMessageBox = mBar->addMenu("标准对话框");

    QAction* actTmp;
    actTmp = pMessageBox->addAction("about");
    connect(actTmp, &QAction::triggered, [=]() {
        QMessageBox::about(this, "about", "this is an about messageBox");
        });
    actTmp = pMessageBox->addAction("about Qt");
    connect(actTmp, &QAction::triggered, [=]() {
        QMessageBox::aboutQt(0, "about Qt");
        });
    actTmp = pMessageBox->addAction("question");
    connect(actTmp, &QAction::triggered, [=]() {
        int rst = QMessageBox::question(this, "question", "Are you ok?");
        if (rst == QMessageBox::Yes)
        {
            qDebug() << "click yes";
        }
        else if (rst == QMessageBox::No)
        {
            qDebug() << "click no";
        }
        });
}
