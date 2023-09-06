#pragma once

#include <QtWidgets/QMainWindow>
#include "SARibbon.h"

class MainWindow : public SARibbonMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setupRibbonUi();
    SARibbonMainWindow* widget = new SARibbonMainWindow();

public slots:
    void test_show();
    void test_hide();
};
