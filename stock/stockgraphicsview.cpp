#include "stockgraphicsview.h"
#include <iostream>
#include "stocksocket.h"
#include "stockedge.h"
#include <QMenu>
#include <QApplication>
int MODE_NO_OPERATION = 1;
int MODE_EDGE_DRAG = 2;
int MODE_CUTTING_LINE = 3;

StockGraphicsView::StockGraphicsView(QWidget *parent): QGraphicsView(parent){
    //this->setStyleSheet(QString(
    // "background-color: #FFFFFF;border-width: 2px;border-radius:2px;border-style: inset;border-color: #FFFFFF;"));
    m_remove_action = new QAction("delete item",this);
    connect(m_remove_action, SIGNAL(triggered()),this, SLOT(RemoveSelectedItems()));
    m_mode = MODE_NO_OPERATION;
}
StockGraphicsView::~StockGraphicsView(){}


void StockGraphicsView::SetStockGraphicScene(StockGraphicsScene *stock_graphics_scene)
{
    m_stock_graphics_scene = stock_graphics_scene;
}

void StockGraphicsView::SetStockGraphicsCuttingLine(StockGraphicsCuttingLine *stock_graphics_cutting_line)
{
    this->m_stock_graphics_cutting_line = stock_graphics_cutting_line;
}



void StockGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
     std::cout<<"mouse is moving"<<std::endl;
     if(this->m_mode == MODE_CUTTING_LINE)
     {
         QPointF pos = mapToScene(event->pos());
         std::cout<<"mouse is moving"<<pos.rx()<<std::endl;
         m_stock_graphics_cutting_line->AppendQPoint(pos.toPoint());
         m_stock_graphics_cutting_line->update();
     }


     QGraphicsView::mouseMoveEvent(event);
     //StockEdge* stock_edge = static_cast<StockEdge*>(this->m_drag_stock_edge_interface);
     //stock_edge->SetTarget(event->pos());
}

void StockGraphicsView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsItem* item =this->itemAt(event->pos());
    if(event->button() == Qt::LeftButton)
    {
        if (item == nullptr)
        {
            this->m_mode = MODE_CUTTING_LINE;
            QMouseEvent* fake_event = new QMouseEvent(QEvent::MouseButtonRelease,event->localPos(),
                                                 event->screenPos(), Qt::LeftButton, Qt::NoButton,
                                                 event->modifiers());
            QGraphicsView::mouseReleaseEvent(fake_event);
            QApplication::setOverrideCursor(Qt::CrossCursor);
            return;
        }
        if(StockGraphicsSocket* v=dynamic_cast<StockGraphicsSocket*>(item))
        {
           if(m_mode == MODE_NO_OPERATION)
           {
               this->m_mode = MODE_EDGE_DRAG;
               std::cout<<"end dragging edge"<<std::endl;
               if(StockGraphicsSocket* v=dynamic_cast<StockGraphicsSocket*>(item))
               {
                   std::cout<<"assign end socket"<<std::endl;
               }
               return;
           }
        }
    }
    /*
    if(event->modifiers() & Qt::ShiftModifier)
    {
        std::cout<<"all modifiers: "<<event->modifiers()<<std::endl;
        std::cout<<(event->modifiers() | Qt::ShiftModifier)<<std::endl;
        std::cout<<"left click + shift"<<std::endl;
        event->ignore();
        QMouseEvent* fake_event = new QMouseEvent(QEvent::MouseButtonPress, event->localPos()
                                             , Qt::LeftButton, event->buttons() | Qt::LeftButton
                                             , event->modifiers() | Qt::ControlModifier);
        QGraphicsView::mousePressEvent(fake_event);
        return;
    }

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
    }*/

    QGraphicsView::mousePressEvent(event);
}

void StockGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsItem* item =this->itemAt(event->pos());
    if(event->button() == Qt::LeftButton)
    {
        if(this->m_mode == MODE_CUTTING_LINE)
        {
            m_mode = MODE_NO_OPERATION;
            QApplication::setOverrideCursor(Qt::ArrowCursor);
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
    }
    if(event->modifiers() & Qt::ShiftModifier)
    {
        std::cout<<"left release + shift"<<std::endl;
        event->ignore();
        QMouseEvent* fake_event = new QMouseEvent(event->type(), event->localPos()
                                             , Qt::LeftButton, Qt::NoButton
                                             , event->modifiers() | Qt::ControlModifier);
        QGraphicsView::mouseReleaseEvent(fake_event);
        return;
    }


    QGraphicsView::mouseReleaseEvent(event);
}


void StockGraphicsView::RemoveSelectedItems()
{
    QList<QGraphicsItem*> items_selected = m_stock_graphics_scene->selectedItems();
    QList<QGraphicsItem*> items = m_stock_graphics_scene->items();
    std::cout<<"items selected size: "<<items_selected.size()<<std::endl;
    std::cout<<"items size: "<<items.size()<<std::endl;
}

void StockGraphicsView::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(m_remove_action);
    menu.exec(event->globalPos());
}
