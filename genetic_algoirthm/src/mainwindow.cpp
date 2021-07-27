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
    ui->customplot->addGraph();
    ui->customplot->addGraph();

    ga = new CrowdingGA(20);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->customplot->xAxis->setRange(0,1);
    ui->customplot->yAxis->setRange(0,1.2);
    QVector<double> a, b;
    for(int i=0; i<2000; i++){
        a.push_back(1.0*((double)i)/2000.0);
        b.push_back(problem::SO::M1(1.0*((double)i)/2000.0));
    }
    ui->customplot->graph(0)->setData(a,b);

    ui->customplot->graph(1)->data()->clear();
    QVector<double> x,y;
    ga->Selection();
    ga->Crossover();
    std::vector<Chromosome> pop = ga->GetPopulation();
    for(auto itr=pop.begin(); itr!=pop.end(); itr++)
    {
        std::vector<int> chromo = itr->GetChromosome();
        double pos = BinaryString2RealNormalization(chromo);
        x.push_back(pos);
        y.push_back(problem::SO::M1(pos));
    }
    ui->customplot->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->customplot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::white, Qt::red,7));
    ui->customplot->graph(1)->setData(x,y);
    ui->customplot->replot();
}

void MainWindow::on_pushButton_nsga_clicked()
{


    NSGA nsga(30);
    nsga.SelectionOperator();
    std::vector<NSGAChromosome> pop = nsga.GetPopulation();
    std::vector<std::vector<NSGAChromosome>> fronters = nsga.GetFronters();


    QVector<double> f1, f2;
    for(auto itr=pop.begin(); itr!=pop.end(); itr++)
    {
        f1.push_back(itr->GetFirstFitness());
        f2.push_back(itr->GetSecondFitness());
    }

    ui->customplot->xAxis->setRange(*std::min_element(f1.constBegin(),f1.constEnd()),
                                    *std::max_element(f1.constBegin(),f1.constEnd()));
    ui->customplot->yAxis->setRange(*std::min_element(f2.constBegin(),f2.constEnd()),
                                    *std::max_element(f2.constBegin(),f2.constEnd()));
    ui->customplot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->customplot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::white, Qt::red,7));
    ui->customplot->graph(0)->setData(f1,f2);
 ;

    //draw fronter
    for(unsigned long k=0; k< fronters.size(); k++){
        ui->customplot->addGraph();
        QVector<double> fronter_f1, fronter_f2;
        for(unsigned long i=0; i<fronters[k].size(); i++){
            fronter_f1.push_back(fronters[k][i].GetFirstFitness());
            fronter_f2.push_back(fronters[k][i].GetSecondFitness());
        }
        int r = GenerateRandomNumber(0,255);
        int g = GenerateRandomNumber(0,255);
        int b = GenerateRandomNumber(0,255);
        ui->customplot->graph(k)->setLineStyle(QCPGraph::lsNone);
        ui->customplot->graph(k)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::white, QColor(r,g,b,255),7));
        ui->customplot->graph(k)->setData(fronter_f1,fronter_f2);
    }

    ui->customplot->replot();
}
