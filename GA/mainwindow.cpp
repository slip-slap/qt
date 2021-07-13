#include "mainwindow.h"
#include "./ui_mainwindow.h"


namespace problem
{
    namespace SCH
    {
        double TargetFunction1(double x)
        {
            return x * x;
        }
        double TargetFunction2(double x)
        {
            return (x - 2) * (x - 2);
        }
    }
}




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->customplot->addGraph()->setPen(QPen(Qt::red));
    ui->customplot->addGraph()->setPen(QPen(Qt::blue));

    QVector<double> x;
    QVector<double> value1;
    QVector<double> value2;
    for(int i = 1;i < 1000;i++)
    {
        double key = -1000 + 2000*i/1000;
        x.push_back(key);
        value1.push_back(problem::SCH::TargetFunction1(key));
        value2.push_back(problem::SCH::TargetFunction2(key));
    }

    ui->customplot->graph(0)->setData(x, value1);
    ui->customplot->graph(0)->setData(x, value2);
    ui->customplot->xAxis->setRange(-1000,1000);
    ui->customplot->yAxis->setRange(-50,200000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

