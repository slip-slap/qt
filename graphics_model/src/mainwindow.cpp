#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QFileDialog>

#include "gmnode.h"
#include "gmsocket.h"
#include "gmedge.h"
#include "gmqtgraphicscuttingline.h"
#include <fstream>

#include "json/json.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    std::cout<<"it start"<<std::endl;
    ui->setupUi(this);
    /*ui->statusbar->setStyleSheet("background-color: rgb(255,255,255); color : black;");
    ui->menubar->setStyleSheet("background-color: rgb(255,255,255); color : black;");
    ui->toolBar->setStyleSheet("background: white; spacing: 0px;");*/
    ui->menubar->setNativeMenuBar(false);
    m_scene = new GMScene();
    GMQtGraphicsCuttingLine* cutting_line = new GMQtGraphicsCuttingLine((GMQtGraphicScene*)m_scene->GetGraphicsScenePtr());
    GMNode* gm_node = new GMNode(m_scene);
    gm_node->SetStockNodePosition(QPointF(50,50));
    GMNode* gm_node2 = new GMNode(m_scene);
    gm_node2->SetStockNodePosition(QPointF(200,200));
    GMNode* gm_node3 = new GMNode(m_scene);
    gm_node3->SetStockNodePosition(QPointF(400,100));
    new GMEdge(m_scene, gm_node,POSITION::SOUTH_ANCHOR, gm_node2,POSITION::NORTH_ANCHOR);
    new GMEdge(m_scene, gm_node2,POSITION::NORTH_ANCHOR, gm_node3,POSITION::NORTH_ANCHOR);

    this->ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    this->ui->graphicsView->setRenderHint(QPainter::HighQualityAntialiasing);
    this->ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    this->ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->ui->graphicsView->setScene(m_scene->GetGraphicsScenePtr());
    this->ui->graphicsView->SetStockGraphicScene((GMQtGraphicScene*)(m_scene->GetGraphicsScenePtr()));
    this->ui->graphicsView->SetGMQtGraphicsCuttingLine(cutting_line);
    this->ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);

    m_scene->GetGraphicsScenePtr()->setBackgroundBrush(Qt::black);
    m_scene->GetGraphicsScenePtr()->setSceneRect(-100,-100,1000,1000);


    timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()),scene,SLOT(advance()));
    //connect(timer, SIGNAL(timeout()),scene,SLOT(update()));
    //connect(timer, SIGNAL(timeout()),this,SLOT(foo()));
    //timer->start(10);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::foo()
{


}


void MainWindow::on_actionExit_2_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionOpen_triggered()
{


    //QString file_name = QFileDialog::getOpenFileName();
    //std::ifstream i(file_name.toStdString());
    std::ifstream i("/Users/kismet/Desktop/output.json");
    nlohmann::json json_file;
    i >> json_file;
    i.close();
    m_scene->deserialize(json_file.dump(4));
    for(int ll=0; ll < json_file["node"].size(); ll++ ){
        std::cout<<json_file["node"][ll]["socket1"].dump(8)<<std::endl;
    }
    //std::cout<<json_file["edge"].dump(8);
    /**/
}

void MainWindow::on_actionZoom_In_triggered()
{
     ui->graphicsView->scale(2,2);
}

void MainWindow::on_actionZoom_Out_triggered()
{
     ui->graphicsView->scale(0.5, 0.5);
}

void MainWindow::on_actionSave_triggered()
{
     ui->statusbar->showMessage("you are going save file");
     std::ofstream seriable;
     seriable.open("/Users/kismet/Desktop/output.json");
     nlohmann::json js;
     seriable<<js.parse(m_scene->serialize()).dump(4)<<std::endl;
     //std::cout<<std::setw(4)<<js<<std::endl;
     seriable.close();
}

void MainWindow::on_actionClear_triggered()
{
    m_scene->ClearScene();
}
