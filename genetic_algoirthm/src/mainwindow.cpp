#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "ga_problem.h"
#include "crowdingga.h"
#include "ga_tool.h"
#include "nsga.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->customplot->xAxis->setRange(0,1);
    ui->customplot->yAxis->setRange(0,1.2);
    ui->customplot->addGraph();
    ui->customplot->addGraph();

    ga = new CrowdingGA(20);


    QVector<double> a, b;
    for(int i=0; i<2000; i++){
        a.push_back(1.0*((double)i)/2000.0);
        b.push_back(problem::SO::M1(1.0*((double)i)/2000.0));
    }
    ui->customplot->graph(0)->setData(a,b);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{


    ui->customplot->graph(1)->data()->clear();
    QVector<double> x,y;
    ga->Selection();
    ga->Crossover();
    std::vector<Chromosome> pop = ga->GetPopulation();
    for(auto itr=pop.begin(); itr!=pop.end(); itr++)
    {
        std::vector<int> chromo = itr->GetChromosome();
        double pos = BinaryString2RealNormalization(chromo,30);
        x.push_back(pos);
        y.push_back(problem::SO::M1(pos));
    }
    ui->customplot->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->customplot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::white, Qt::red,7));
    ui->customplot->graph(1)->setData(x,y);
    ui->customplot->replot();
}
