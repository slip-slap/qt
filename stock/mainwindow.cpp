#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
#include <QGraphicsEllipseItem>
#include <QPainter>

#include "stockscene.h"
#include "stocknode.h"
#include "stocksocket.h"
#include "stockedge.h"
#include "stockgraphicscuttingline.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*ui->statusbar->setStyleSheet("background-color: rgb(255,255,255); color : black;");
    ui->menubar->setStyleSheet("background-color: rgb(255,255,255); color : black;");
    ui->toolBar->setStyleSheet("background: white; spacing: 0px;");*/
    ui->menubar->setNativeMenuBar(false);
    StockScene* scene = new StockScene();
    StockGraphicsCuttingLine* cutting_line = new StockGraphicsCuttingLine((StockGraphicsScene*)scene->GetGraphicsScenePtr());
    StockSocket* socket11 = new StockSocket();
    StockSocket* socket12 = new StockSocket();
    StockSocket* socket21 = new StockSocket();
    StockSocket* socket22 = new StockSocket();
    StockSocket* socket31 = new StockSocket();
    StockSocket* socket32 = new StockSocket();
    (new StockNode(scene,"first",socket11,socket12))->SetStockNodePosition(QPointF(50,50));
    (new StockNode(scene,"second",socket21, socket22))->SetStockNodePosition(QPointF(200,200));
    (new StockNode(scene,"third",socket31, socket32))->SetStockNodePosition(QPointF(400,100));

    new StockEdge(scene, socket12,socket21);
    new StockEdge(scene, socket22,socket31);
    this->ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    this->ui->graphicsView->setRenderHint(QPainter::HighQualityAntialiasing);
    this->ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    this->ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->ui->graphicsView->setScene(scene->GetGraphicsScenePtr());
    this->ui->graphicsView->SetStockGraphicScene((StockGraphicsScene*)(scene->GetGraphicsScenePtr()));
    this->ui->graphicsView->SetStockGraphicsCuttingLine(cutting_line);
    this->ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);

    scene->GetGraphicsScenePtr()->setBackgroundBrush(Qt::black);
    scene->GetGraphicsScenePtr()->setSceneRect(-100,-100,1000,1000);

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
    ui->statusbar->showMessage("you are going open file");
}

void MainWindow::on_actionZoom_In_triggered()
{
     ui->graphicsView->scale(2,2);
}

void MainWindow::on_actionZoom_Out_triggered()
{
     ui->graphicsView->scale(0.5, 0.5);
}
