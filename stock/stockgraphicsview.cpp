#include "stockgraphicsview.h"
#include <iostream>
#include "stocksocket.h"

StockGraphicsView::StockGraphicsView(QWidget *parent): QGraphicsView(parent)
{
    std::cout<<"graphics view constructor"<<std::endl;
}


StockGraphicsView::~StockGraphicsView()
{

}

void StockGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
     //std::cout<<"mouse is moving"<<std::endl;
     QGraphicsView::mouseMoveEvent(event);
}

void StockGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        //this->setDragMode(QGraphicsView::ScrollHandDrag);
        QGraphicsView::mousePressEvent(event);
        QPointF pos = event->pos();
        QGraphicsItem* item = this->itemAt(pos.rx(), pos.ry());
        QPointF local_pos = event->localPos();
        QPointF screen_pos = event->screenPos();
        std::cout<<"local pos: x="<<local_pos.rx()<<", y="<<local_pos.ry()<<std::endl;
        std::cout<<"screen pos: x="<<screen_pos.rx()<<", y="<<screen_pos.ry()<<std::endl;

    }
    if(event->button() == Qt::RightButton)
    {
        QGraphicsView::mousePressEvent(event);
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
