#include "DesignerSimpleSample.h"

DesignerSimpleSample::DesignerSimpleSample(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    QObject::connect(ui.cbx_underline, SIGNAL(clicked(bool)), this, SLOT(on_cbx_underline_clicked(bool)));
}

DesignerSimpleSample::~DesignerSimpleSample()
{}

void DesignerSimpleSample::on_cbx_underline_clicked(bool status)
{
    QFont font = ui.plainTextEdit->font();
    font.setUnderline(status);
    ui.plainTextEdit->setFont(font);
}
