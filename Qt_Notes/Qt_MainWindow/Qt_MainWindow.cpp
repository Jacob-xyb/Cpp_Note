#include "Qt_MainWindow.h"
#include <QSplitter>
#include <QTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>

Qt_MainWindow::Qt_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Qt_MainWindowClass())
{
    ui->setupUi(this);
}

Qt_MainWindow::~Qt_MainWindow()
{
    delete ui;
}
