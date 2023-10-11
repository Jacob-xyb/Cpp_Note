#include "QCustomPlotTest.h"

QCustomPlotTest::QCustomPlotTest(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QCustomPlotTestClass())
{
    ui->setupUi(this);
    draw_parabola();
}

QCustomPlotTest::~QCustomPlotTest()
{
    delete ui;
}

void QCustomPlotTest::draw_parabola()
{
    // 生成数据，画出的是抛物线
    QVector<double> x(101), y(101); //初始化向量x和y
    for (int i = 0; i < 101; ++i)
    {
        x[i] = i / 50.0 - 1; // x范围[-1,1]
        y[i] = x[i] * x[i]; // y=x*x
    }
    ui->customPlot->addGraph();//添加数据曲线（一个图像可以有多个数据曲线）

    // graph(0);可以获取某个数据曲线（按添加先后排序）
    // setData();为数据曲线关联数据
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->graph(0)->setName("第一个示例");// 设置图例名称
    // 为坐标轴添加标签
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // 设置坐标轴的范围，以看到所有数据
    ui->customPlot->xAxis->setRange(-1, 1);
    ui->customPlot->yAxis->setRange(0, 1);
    ui->customPlot->legend->setVisible(true); // 显示图例
    // 重画图像
    ui->customPlot->replot();
}
