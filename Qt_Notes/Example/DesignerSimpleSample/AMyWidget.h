#pragma once
#include <QtWidgets/QDialog>
#include "ui_AMyWidget.h"
#include "CustomToolbars.h"


class AMyWidget : public QDialog
{
    Q_OBJECT
    
public:
    AMyWidget(QWidget* parent = nullptr);
    ~AMyWidget();

private:
    void initSignalSlots();


private slots:
    void on_btn_FontConversion_clicked();
    void on_btn_CustomToolbars_clicked(); 

private:
    Ui::AMyWidget ui;
    CustomToolbars* w = new CustomToolbars;
};

