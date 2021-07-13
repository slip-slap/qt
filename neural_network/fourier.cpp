#include "fourier.h"
#include "ui_fourier.h"
double polynominal(double x){
    return x*x - 6* x + 1;
}

double simulation(double x){
    return  15*std::cos(3*x) +
            -0.5918*std::cos(4*x)+
            22*std::sin(x)+
            22*std::sin(2*x)
            ;
}

Fourier::Fourier(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Fourier)
{
    ui->setupUi(this);
}

Fourier::~Fourier()
{
    delete ui;
}

void Fourier::on_pushButton_clicked()
{

    QVector<double> a;
    QVector<double> b;
    QVector<double> c;
    for(double i=0;i<1000;i=i+1){

        a.push_back(i*8/1000);
        b.push_back(polynominal(i*8/1000));
        c.push_back(simulation(i));
    }

    ui->customWidget->addGraph();
    ui->customWidget->addGraph();
    ui->customWidget->graph(0)->setData(a,b);
    ui->customWidget->graph(1)->setData(a,c);
    ui->customWidget->xAxis->setRange(0,25);
    ui->customWidget->yAxis->setRange(-30,40);
    ui->customWidget->replot();

}
