#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_Style.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Qt_StyleClass; };
QT_END_NAMESPACE

class Qt_Style : public QMainWindow
{
    Q_OBJECT

public:
    Qt_Style(QWidget *parent = nullptr);
    ~Qt_Style();

private:
    Ui::Qt_StyleClass *ui;
};
