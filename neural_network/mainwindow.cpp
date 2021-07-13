#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "myitem.h"
#include "circle.h"
#include "line.h"
#include "neuralnetwork.h"

#include <vector>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0, 0, 350,250);
    std::cout<<"width is: "<<scene->sceneRect().width()<<std::endl;

    QBrush redBrush(Qt::red);

    QPen redPen(QColor(255, 255, 0, 127));

    QLineF TopLine(scene->sceneRect().topLeft(),scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(),scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(),scene->sceneRect().bottomRight());
    QLineF BottomLine(scene->sceneRect().bottomLeft(),scene->sceneRect().bottomRight());
    scene->addLine(TopLine, redPen);
    scene->addLine(LeftLine, redPen);
    scene->addLine(RightLine,redPen);
    scene->addLine(BottomLine, redPen);

    //Line*  line = new Line();
    //Line*  line2 = new Line();
    //scene->addItem(line);
    //scene->addItem(line2);


    NeuralNetwork* nn = new NeuralNetwork();
    scene->addItem(nn);
    for(std::vector<std::tuple<QLineF,QColor>>::iterator itr=nn->vector_of_tuple.begin(); itr!=nn->vector_of_tuple.end();itr++){
        scene->addLine(std::get<0>(*itr),std::get<1>(*itr));
    }

    for(std::vector<Circle*>::iterator itr=nn->vector_of_circle.begin(); itr!=nn->vector_of_circle.end();itr++){
        scene->addItem(*itr);
    }


   // ellipse = scene->addEllipse(10,10,100,100,redPen,redBrush);
   // scene->addRect(-100,-100,50,50,redPen,redBrush);

    /*
    std::vector<std::vector<Circle*>> vector_of_circle_vector;
    int number_of_layer = 4;
    std::vector<int> nodes_each_layer={5,10,8,3};
    int startPosx = -200;
    int startPosy = -200;
    int column_distance = 80;

    for(int i = 0;i < number_of_layer; i++){
        std::vector<Circle*> circleVector;
        for (int k = 0;k < nodes_each_layer[i]; k++){
            Circle *circle = new Circle();
            startPosy = startPosy + 250/nodes_each_layer[i];
            circle->setPos(startPosx,startPosy);
            scene->addItem(circle);
            circleVector.push_back(circle);
        }
        startPosx = startPosx + column_distance;
        startPosy = -200;
        std::cout<<circleVector.size()<<std::endl;
        vector_of_circle_vector.push_back(circleVector); 
     }


     std::vector<std::vector<Circle*>>::iterator itr0=vector_of_circle_vector.begin();
     for(int i=0;i<3;i++){
         std::vector<Circle*> previous_column = *itr0;
         itr0++;
         std::vector<Circle*> current_column = *itr0;
         for (std::vector<Circle*>::iterator itr = current_column.begin(); itr != current_column.end();itr++){
             for(std::vector<Circle*>::iterator itr_pre = previous_column.begin(); itr_pre != previous_column.end(); itr_pre++){
                 QLineF line0((*itr)->pos(),(*itr_pre)->pos());
                 scene->addLine(line0,redPen);
             }
         }
     }*/

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timer, SIGNAL(timeout()),scene,SLOT(update()));
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->graphicsView->rotate(10);
}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog d;
    d.exec();

}

void MainWindow::on_pushButton_3_clicked()
{

    //this->hide();
}
