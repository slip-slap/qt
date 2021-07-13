#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "fourier.h"
#include <QVector>
#include <QPen>
#include <math.h>
#include <iostream>

double f(double x){
    return 7*std::sin(x) + 5*std::cos(3*x);
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->addGraph()->setPen(QPen(Qt::red));
    int frequency =  ui->lineEdit->text().toInt();;
    fourier::target_function = &f;
    fourier::simulation(frequency);


    QVector<double> a;
    QVector<double> b;
    QVector<double> c;
    for(double i=0;i<1000;i=i+1){

        a.push_back(i*8/1000);
        b.push_back(f(i*8/1000));
        c.push_back(fourier::fourier_expansion(i*8/1000));
    }


    ui->widget->graph(0)->setData(a,b);
    ui->widget->graph(1)->setData(a,c);
    ui->widget->xAxis->setRange(0,10);
    ui->widget->yAxis->setRange(-20,20);
    ui->widget->replot();
}
