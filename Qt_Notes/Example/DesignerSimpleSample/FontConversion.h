#pragma once

#include <QtWidgets/QDialog>
#include "ui_FontConversion.h"

class FontConversion : public QDialog
{
    Q_OBJECT

public:
    FontConversion(QWidget *parent = nullptr);
    ~FontConversion();

private slots:
    void on_cbx_underline_clicked(bool status);
    void on_cbx_italic_clicked(bool status);
    void on_cbx_bold_clicked(bool status);
    void setTextFontColor(bool status);

private:
    Ui::FontConversion ui;
};
