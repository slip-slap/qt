#include <iostream>
#include <fstream>
#include "stdlib.h"

#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "ga_problem.h"
#include "crowdingga.h"
#include "ga_tool.h"
#include "nsga.h"
#include "csv.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->customplot->addGraph();
    ui->customplot->addGraph();

    ga = new CrowdingGA(20);

    nsga = new NSGA(30);

    m_color_qvec.push_back(QColor(0,0,0,255));
    m_color_qvec.push_back(QColor(255,0,0,255));
    m_color_qvec.push_back(QColor(0,255,0,255));
    m_color_qvec.push_back(QColor(0,0,255,255));
    m_color_qvec.push_back(QColor(255,255,0,255));
    m_color_qvec.push_back(QColor(0,255,255,255));
    m_color_qvec.push_back(QColor(255,0,255,255));
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
    nsga->SelectionOperator();
    nsga->CrossoverOperator();
    std::vector<NSGAChromosome>& pop = nsga->GetPopulation();
    std::vector<std::vector<NSGAChromosome>> fronters = nsga->GetFronters();



    QVector<double> f1, f2;
    for(auto itr=pop.begin(); itr!=pop.end(); itr++)
    {
        f1.push_back(itr->GetIndexedFitness(1));
        f2.push_back(itr->GetIndexedFitness(0));
    }
    ui->customplot->xAxis->setLabel("Mass");
    ui->customplot->yAxis->setLabel("Negative of Strength Ratio");
    double min_x = *std::min_element(f1.constBegin(),f1.constEnd());
    double max_x = *std::max_element(f1.constBegin(),f1.constEnd());
    double min_y = *std::min_element(f2.constBegin(),f2.constEnd());
    double max_y = *std::max_element(f2.constBegin(),f2.constEnd());
    double scalar_xaxis = (max_x - min_x) *  0.1;
    min_x = min_x - scalar_xaxis/2;
    max_x = max_x + scalar_xaxis/2;
    double scalar_yaxis = (max_y - min_y) * 0.1;
    min_y = min_y - scalar_yaxis/2;
    max_y = max_y + scalar_yaxis/2;

    ui->customplot->xAxis->setRange(min_x, max_x);
    ui->customplot->yAxis->setRange(min_y, max_y);
    ui->customplot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->customplot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::white, Qt::red,7));
    ui->customplot->graph(0)->data()->clear();
    ui->customplot->graph(0)->setData(f1,f2);

    //draw fronter
    for(unsigned long k=0; k< fronters.size(); k++){
        ui->customplot->addGraph();
        QVector<double> fronter_f1, fronter_f2;
        for(unsigned long i=0; i<fronters[k].size(); i++){
            fronter_f1.push_back(fronters[k][i].GetIndexedFitness(1));
            fronter_f2.push_back(fronters[k][i].GetIndexedFitness(0));
        }
        ui->customplot->graph(k)->setPen(QPen(m_color_qvec[k%6]));
        ui->customplot->graph(k)->setLineStyle(QCPGraph::lsLine);
        ui->customplot->graph(k)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::white, m_color_qvec[k%6],7));
        ui->customplot->graph(k)->data()->clear();
        ui->customplot->graph(k)->setData(fronter_f1,fronter_f2);
    }

    ui->customplot->replot();

}

void MainWindow::on_pushButton_2_clicked()
{
    std::cout<<"save picture"<<std::endl;
    ui->customplot->savePng("./plot");
}

void MainWindow::on_pushButton_display_first_fronter_clicked()
{
     std::vector<std::vector<NSGAChromosome>> fronters = nsga->GetFronters();
     //draw fronter
         ui->customplot->clearGraphs();
         ui->customplot->addGraph();
         QVector<double> fronter_f1, fronter_f2;
         for(unsigned long i=0; i<fronters[0].size(); i++)
         {
             fronter_f1.push_back(fronters[0][i].GetIndexedFitness(1));
             fronter_f2.push_back(fronters[0][i].GetIndexedFitness(0));
         }
         ui->customplot->graph(0)->setPen(QPen(m_color_qvec[0%6]));
         ui->customplot->graph(0)->setLineStyle(QCPGraph::lsLine);
         ui->customplot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::white, m_color_qvec[0%6],7));
         ui->customplot->graph(0)->data()->clear();
         ui->customplot->graph(0)->setData(fronter_f1,fronter_f2);


     ui->customplot->replot();
}
