#pragma once

#include <QtWidgets/QWidget>
#include "ui_QCustomPlotTest.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QCustomPlotTestClass; };
QT_END_NAMESPACE

#pragma execution_character_set("UTF-8")

class QCustomPlotTest : public QWidget
{
    Q_OBJECT

public:
    QCustomPlotTest(QWidget *parent = nullptr);
    ~QCustomPlotTest();

    void draw_parabola();

private:
    Ui::QCustomPlotTestClass *ui;
};
