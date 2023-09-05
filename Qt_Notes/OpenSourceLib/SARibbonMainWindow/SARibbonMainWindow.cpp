#include "SARibbonMainWindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : SARibbonMainWindow(parent)
{
    resize(1200, 800);
    QObject::connect(this->ribbonBar()->applicationButton(), SIGNAL(clicked()), this, SLOT(test_hide()));
    setupRibbonUi();

}

MainWindow::~MainWindow()
{}

void MainWindow::setupRibbonUi()
{
    // ÉèÖÃ SARibbonBar
    SARibbonBar* ribbon = this->ribbonBar();

    ribbon->setRibbonStyle(SARibbonBar::WpsLiteStyleTwoRow);
    ribbon->applicationButton()->setText(tr(" File "));
}

void MainWindow::test_hide()
{
    cout << "xxx" << endl;
    this->hide();
}
