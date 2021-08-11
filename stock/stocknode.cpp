#include "stocknode.h"
#include "stocksocket.h"
#include <iostream>

StockNode::StockNode(QGraphicsScene *scene, StockSocketInterface* stock_socket_interface)
{
    m_stock_socket_interface1 = stock_socket_interface;
    m_stock_graphics_node = new StockGraphicsNode();
    m_stock_socket_interface1->GetStockGraphicsSocket()->setParentItem(m_stock_graphics_node);
    scene->addItem(m_stock_graphics_node);
    scene->addItem(m_stock_socket_interface1->GetStockGraphicsSocket());

}



StockNode::StockNode(StockScene *stock_scene, std::string title,
                     StockSocketInterface* socket1)
{
    m_stock_graphics_node = new StockGraphicsNode(this,title);
    m_stock_socket_interface1 = socket1;
    //m_stock_socket_interface = new StockSocket(this);
    m_stock_socket_interface1->GetStockGraphicsSocket()->setPos(m_stock_graphics_node->pos()+ QPointF(80,0));
    m_stock_socket_interface1->GetStockGraphicsSocket()->setParentItem(m_stock_graphics_node);
    stock_scene->AddNode(this);

}

StockNode::StockNode(StockScene *stock_scene, std::string title, StockSocketInterface *socket1, StockSocketInterface *socket2)
{
    m_stock_graphics_node = new StockGraphicsNode(this,title);
    m_stock_socket_interface1= socket1;
    m_stock_socket_interface2= socket2;
    //m_stock_socket_interface = new StockSocket(this);
    m_stock_socket_interface1->GetStockGraphicsSocket()->setPos(m_stock_graphics_node->pos()+ QPointF(40,0));
    m_stock_socket_interface1->GetStockGraphicsSocket()->setParentItem(m_stock_graphics_node);
    m_stock_socket_interface2->GetStockGraphicsSocket()->setPos(m_stock_graphics_node->pos()+ QPointF(40,90));
    m_stock_socket_interface2->GetStockGraphicsSocket()->setParentItem(m_stock_graphics_node);
    stock_scene->AddNode(this);
}

StockGraphicsNode *StockNode::GetStockGraphicsNode()
{
    return m_stock_graphics_node;
}


QPointF StockNode::GetStockSocketPosition()
{
    return QPointF(100,100);
}

StockSocketInterface *StockNode::GetStockSocketInterface()
{
    return m_stock_socket_interface1;
}

void StockNode::SetStockNodePosition(QPointF pos)
{
    m_stock_graphics_node->setPos(pos);
}

void StockNode::UpdateConnectedEdge()
{
    std::cout<<"update edges with related socket"<<std::endl;
    if(m_stock_socket_interface1!=nullptr){
        if(m_stock_socket_interface1->GetStockEdge()!=nullptr){
           m_stock_socket_interface1->GetStockEdge()->UpdatePositions();
        }
    }
    if(m_stock_socket_interface2!=nullptr){
        if(m_stock_socket_interface2->GetStockEdge()!=nullptr){
           m_stock_socket_interface2->GetStockEdge()->UpdatePositions();
        }
    }
}

QPointF StockNode::GetStockNodePosition()
{
    return m_stock_graphics_node->pos();
}
