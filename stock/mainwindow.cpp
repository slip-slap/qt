#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
#include <QGraphicsEllipseItem>
#include <QPainter>

#include "stockscene.h"
#include "stocknode.h"
#include "stocksocket.h"
#include "stockedge.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    StockScene* scene = new StockScene();
    StockSocket* socket1 = new StockSocket();
    StockSocket* socket2 = new StockSocket();
    (new StockNode(scene,"first",socket1))->SetStockNodePosition(QPointF(50,50));
    (new StockNode(scene,"second",socket2))->SetStockNodePosition(QPointF(200,200));

    new StockEdge(scene, socket1,socket2);
    this->ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    this->ui->graphicsView->setRenderHint(QPainter::HighQualityAntialiasing);
    this->ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    this->ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->ui->graphicsView->setScene(scene->GetGraphicsScenePtr());

    scene->GetGraphicsScenePtr()->setBackgroundBrush(Qt::black);
    scene->GetGraphicsScenePtr()->setSceneRect(-100,-100,1000,1000);
    QGraphicsEllipseItem* item = scene->GetGraphicsScenePtr()->addEllipse(0,0,60,60,QPen(Qt::white));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setFlag(QGraphicsItem::ItemIsSelectable);

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


void MainWindow::on_pushButton_clicked()
{
    ui->graphicsView->scale(3,3);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsView->scale(0.3, 0.3);
}
