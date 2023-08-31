#include "Qt_Basic.h"

Qt_Basic::Qt_Basic(QWidget *parent)
    : QWidget(parent)
{
    b1 = new QPushButton("Hello Qt", this);
    ui.setupUi(this);

    // ≥ı ºªØ
}

Qt_Basic::~Qt_Basic()
{}
