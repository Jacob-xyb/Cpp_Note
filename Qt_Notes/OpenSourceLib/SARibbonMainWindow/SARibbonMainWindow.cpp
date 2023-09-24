#include "SARibbonMainWindow.h"
#include <iostream>
#include <QRadioButton>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : SARibbonMainWindow(parent)
{
    resize(1200, 800);
    this->setWindowTitle("SARibbon");
    QObject::connect(this->ribbonBar()->applicationButton(), SIGNAL(clicked()), this, SLOT(test_hide()));
    QObject::connect(widget->ribbonBar()->applicationButton(), SIGNAL(clicked()), this, SLOT(test_show()));
    setupRibbonUi();
}

MainWindow::~MainWindow()
{
    delete widget;
}

void MainWindow::setupRibbonUi()
{
    // ÉèÖÃ SARibbonBar
    SARibbonBar* ribbon = this->ribbonBar();
    //ribbon->hide();
    ribbon->setRibbonStyle(SARibbonBar::WpsLiteStyle);
    ribbon->applicationButton()->setText(tr(" File "));
    SARibbonCategory* categoryMain = ribbon->addCategoryPage(tr("Main"));
    categoryMain->setObjectName(("categoryMain"));
}

void MainWindow::test_hide()
{
    cout << "xxx" << endl;
    widget->resize(this->size());
    widget->show();
    this->hide();
}

void MainWindow::test_show()
{
    this->show();
    widget->hide();
}
