#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_MainWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Qt_MainWindowClass; };
QT_END_NAMESPACE

class Qt_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Qt_MainWindow(QWidget *parent = nullptr);
    ~Qt_MainWindow();

private:
    Ui::Qt_MainWindowClass *ui;
};
