#include "stockgraphicsview.h"
#include <iostream>
#include "stocksocket.h"
#include "stockedge.h"

StockGraphicsView::StockGraphicsView(QWidget *parent): QGraphicsView(parent){}
StockGraphicsView::~StockGraphicsView(){}

int MODE_NO_OPERATION = 1;
int MODE_EDGE_DRAG = 2;

void StockGraphicsView::SetStockGraphicScene(StockGraphicsScene *stock_graphics_scene)
{
    m_stock_graphics_scene = stock_graphics_scene;
}

void StockGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
     std::cout<<"mouse is moving"<<std::endl;
     QGraphicsView::mouseMoveEvent(event);
     //StockEdge* stock_edge = static_cast<StockEdge*>(this->m_drag_stock_edge_interface);
     //stock_edge->SetTarget(event->pos());
}

void StockGraphicsView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsItem* item =this->itemAt(event->pos());
    if(event->button() == Qt::LeftButton)
    {
        //this->setDragMode(QGraphicsView::ScrollHandDrag);
        if(StockGraphicsSocket* v=dynamic_cast<StockGraphicsSocket*>(item)){
            if(this->m_mode == MODE_NO_OPERATION){
                m_mode = MODE_EDGE_DRAG;
                std::cout<<"start draging edge, and assign start socket"<<std::endl;
                //StockSocketInterface* stock_socket_inference = v->GetStockSocketInterface();
                //this->m_drag_stock_edge_interface = new StockEdge(m_stock_graphics_scene->GetStockScene(),v->GetStockSocketInterface(),event->pos());
                return;
            }
        }
    }

    if (this->m_mode == MODE_EDGE_DRAG)
    {
        this->m_mode = MODE_NO_OPERATION;
        std::cout<<"end dragging edge"<<std::endl;
        if(StockGraphicsSocket* v=dynamic_cast<StockGraphicsSocket*>(item))
        {
            std::cout<<"assign end socket"<<std::endl;
        }
        return;
    }
    QGraphicsView::mousePressEvent(event);
   // QGraphicsView::mousePressEvent(event);
}

void StockGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{

    QGraphicsItem* item =this->itemAt(event->pos());
    if(event->button() == Qt::LeftButton){
        if (this->m_mode == MODE_EDGE_DRAG)
        {
            this->m_mode = MODE_NO_OPERATION;
            std::cout<<"end dragging edge"<<std::endl;
            if(StockGraphicsSocket* v=dynamic_cast<StockGraphicsSocket*>(item))
            {
                std::cout<<"assign end socket"<<std::endl;
            }
            return;
        }
    }
    QGraphicsView::mouseReleaseEvent(event);
}
