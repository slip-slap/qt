#include "stockgraphicsview.h"
#include <iostream>
StockGraphicsView::StockGraphicsView(QWidget *parent): QGraphicsView(parent)
{
    std::cout<<"graphics view constructor"<<std::endl;
}

StockGraphicsView::StockGraphicsView(QGraphicsScene *scene, QWidget *parent): QGraphicsView(scene, parent)
{
    this->setScene(scene);
}

StockGraphicsView::~StockGraphicsView()
{

}

void StockGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
     QGraphicsView::mouseMoveEvent(event);

}

void StockGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        QGraphicsView::mousePressEvent(event);
        QPointF pos = event->pos();
        QGraphicsItem* item = this->itemAt(pos.rx(), pos.ry());

        std::cout<<"socket left button press"<<std::endl;
    }
    if(event->button() == Qt::RightButton)
    {
        QGraphicsView::mousePressEvent(event);
        std::cout<<"socket right button press"<<std::endl;
    }
    else{
        QGraphicsView::mousePressEvent(event);
    }
}

void StockGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
    /*
    if(event->button() == Qt::LeftButton){
        this->setDragMode(QGraphicsView::NoDrag);
    }*/
}
