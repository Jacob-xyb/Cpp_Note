#include "Qt_Style.h"

Qt_Style::Qt_Style(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Qt_StyleClass())
{
    ui->setupUi(this);
}

Qt_Style::~Qt_Style()
{
    delete ui;
}
