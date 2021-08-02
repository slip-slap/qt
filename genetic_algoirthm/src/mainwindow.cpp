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

void CalculateFitness(std::vector<NSGAChromosome>& pop){
    std::ofstream myfile;
    myfile.open("example.csv",std::ios::out);
    myfile<<"number_of_angle_pi, "<< "number_of_angle_zero,"<< "strength_ratio, "<<"mass"<<std::endl;
    for(auto i:pop){myfile<<i;}
    myfile.close();

    std::system("/Users/kismet/.pyenv/shims/python /Users/kismet/Documents/github/prec/recent/research/module1/laminate_multiple_component.py");

    io::CSVReader<4> in("example.csv");
    in.read_header(io::ignore_extra_column,"number_of_angle_pi",
                   "number_of_angle_zero", "strength_ratio","mass");
    int number_of_angle_pi, number_of_angle_zero;
    double strength_ratio, mass;

    int row_index = 0;
    while(in.read_row(number_of_angle_pi,number_of_angle_zero,strength_ratio, mass))
    {
        if(strength_ratio < 0.5)
        {
            pop[row_index].GetFitnessReference()[0] = 1000;
            pop[row_index].GetFitnessReference()[1] = 1000;
        }else{
            pop[row_index].GetFitnessReference()[0] = strength_ratio;
            pop[row_index].GetFitnessReference()[1] = mass;
        }
        row_index++;

    }

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->customplot->addGraph();
    ui->customplot->addGraph();

    ga = new CrowdingGA(20);

    nsga = new NSGA(30);

    m_color_qvec.push_back(QColor(255,0,0,255));
    m_color_qvec.push_back(QColor(0,255,0,255));
    m_color_qvec.push_back(QColor(0,0,255,255));
    m_color_qvec.push_back(QColor(255,0,0,255));
    m_color_qvec.push_back(QColor(0,255,0,255));
    m_color_qvec.push_back(QColor(0,0,255,255));
    m_color_qvec.push_back(QColor(255,0,0,255));
    m_color_qvec.push_back(QColor(0,255,0,255));
    m_color_qvec.push_back(QColor(0,0,255,255));
    m_color_qvec.push_back(QColor(255,0,0,255));
    m_color_qvec.push_back(QColor(0,255,0,255));
    m_color_qvec.push_back(QColor(0,0,255,255));
    m_color_qvec.push_back(QColor(255,0,0,255));
    m_color_qvec.push_back(QColor(0,255,0,255));
    m_color_qvec.push_back(QColor(0,0,255,255));
    m_color_qvec.push_back(QColor(255,0,0,255));
    m_color_qvec.push_back(QColor(0,255,0,255));
    m_color_qvec.push_back(QColor(0,0,255,255));



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
    std::vector<NSGAChromosome> pop = nsga->GetPopulation();
    std::vector<std::vector<NSGAChromosome>> fronters = nsga->GetFronters();



    QVector<double> f1, f2;
    for(auto itr=pop.begin(); itr!=pop.end(); itr++)
    {
        f1.push_back(itr->GetIndexedFitness(0));
        f2.push_back(itr->GetIndexedFitness(1));
    }

    ui->customplot->xAxis->setRange(*std::min_element(f1.constBegin(),f1.constEnd()),
                                    *std::max_element(f1.constBegin(),f1.constEnd()));
    ui->customplot->yAxis->setRange(*std::min_element(f2.constBegin(),f2.constEnd()),
                                    *std::max_element(f2.constBegin(),f2.constEnd()));
    ui->customplot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->customplot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::white, Qt::red,7));
    ui->customplot->graph(0)->setData(f1,f2);

    //draw fronter
    for(unsigned long k=0; k< fronters.size(); k++){
        ui->customplot->addGraph();
        QVector<double> fronter_f1, fronter_f2;
        for(unsigned long i=0; i<fronters[k].size(); i++){
            fronter_f1.push_back(fronters[k][i].GetIndexedFitness(0));
            fronter_f2.push_back(fronters[k][i].GetIndexedFitness(1));
        }
        ui->customplot->graph(k)->setLineStyle(QCPGraph::lsNone);
        ui->customplot->graph(k)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::white, m_color_qvec[k],7));
        ui->customplot->graph(k)->setData(fronter_f1,fronter_f2);
    }

    ui->customplot->replot();

}
