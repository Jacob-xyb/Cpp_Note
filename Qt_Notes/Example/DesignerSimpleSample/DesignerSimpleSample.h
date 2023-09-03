#pragma once

#include <QtWidgets/QDialog>
#include "ui_DesignerSimpleSample.h"

class DesignerSimpleSample : public QDialog
{
    Q_OBJECT

public:
    DesignerSimpleSample(QWidget *parent = nullptr);
    ~DesignerSimpleSample();

public slots:     // connectSlotsByName
    void on_cbx_underline_clicked(bool status);

private:
    Ui::DesignerSimpleSampleClass ui;
};
