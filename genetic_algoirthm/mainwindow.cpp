#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->customplot->xAxis->setRange(0,1);
    ui->customplot->yAxis->setRange(0,1.2);


    QCPGraph* graph = new QCPGraph(ui->customplot->xAxis, ui->customplot->yAxis);
    graph->setPen(QPen(Qt::black));
    QVector<double> a, b;
    for(int i=0; i<2000; i++){
        a.push_back(1.0*((double)i)/2000.0);
        b.push_back(problem::SO::M4(1.0*((double)i)/2000.0));
    }
    graph->setData(a,b);

}

MainWindow::~MainWindow()
{
    delete ui;
}

