#pragma once
#include <QtWidgets/QDialog>
#include "ui_AMyWidget.h"
#include "CustomToolbars.h"
#include "Widget/QTreeWidgetTest.h"

class AMyWidget : public QDialog
{
    Q_OBJECT
    
public:
    AMyWidget(QWidget* parent = nullptr);
    ~AMyWidget();

private:
    void initSignalSlots();

    void keyPressEvent(QKeyEvent* event);

private slots:
    // SimpleSample
    void on_btn_UIDevelopMode_Mixture_clicked();
    void on_btn_UIDevelopMode_Code_clicked();

    void on_btn_CustomToolbars_clicked();
    void on_btn_Splitter_clicked();
    void on_btn_TableView_clicked();
    void on_btn_SizePolicy_clicked();
    void on_btn_MessageBox_clicked();
    void on_btn_QDialog_clicked();
    void on_btn_TreeWidget_clicked();
    void on_btn_QWindowType_clicked();
    void on_btn_QLabel_clicked();
    void on_btn_QLineEdit_clicked();
    void on_btn_QButtonGroup_clicked();

private:
    Ui::AMyWidget ui;
    CustomToolbars* w = new CustomToolbars;
};

