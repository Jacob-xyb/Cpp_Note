#include "FontConversion.h"

FontConversion::FontConversion(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    QObject::connect(ui.rBtn_red, SIGNAL(clicked(bool)), this, SLOT(setTextFontColor(bool)));
    QObject::connect(ui.rBtn_black, SIGNAL(clicked(bool)), this, SLOT(setTextFontColor(bool)));
    QObject::connect(ui.rBtn_blue, SIGNAL(clicked(bool)), this, SLOT(setTextFontColor(bool)));
}

FontConversion::~FontConversion()
{}

void FontConversion::on_cbx_italic_clicked(bool status)
{
    QFont font = ui.plainTextEdit->font();
    font.setItalic(status);
    ui.plainTextEdit->setFont(font);
}

void FontConversion::on_cbx_bold_clicked(bool status)
{
    QFont font = ui.plainTextEdit->font();
    font.setBold(status);
    ui.plainTextEdit->setFont(font);
}

void FontConversion::on_cbx_underline_clicked(bool status)
{
    QFont font = ui.plainTextEdit->font();
    font.setUnderline(status);
    ui.plainTextEdit->setFont(font);
}

void FontConversion::setTextFontColor(bool status)
{
    Qt::GlobalColor color = Qt::black;
    QPalette palette = ui.plainTextEdit->palette();
    if (ui.rBtn_black->isChecked())
    {
        color = Qt::black;
    }
    else if (ui.rBtn_blue->isChecked())
    {
        color = Qt::blue;
    }
    else if (ui.rBtn_red->isChecked())
    {
        color = Qt::red;
    }
    palette.setColor(QPalette::Text, color);

    ui.plainTextEdit->setPalette(palette);
}