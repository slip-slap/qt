#include "stocknode.h"

#include <iostream>

StockNode::StockNode(QGraphicsScene *scene, StockSocketInterface* stock_socket_interface)
{
    m_stock_socket_interface = stock_socket_interface;
    m_stock_graphics_node = new StockGraphicsNode();
    m_stock_socket_interface->GetStockGraphicsSocket()->setParentItem(m_stock_graphics_node);
    scene->addItem(m_stock_graphics_node);
    scene->addItem(m_stock_socket_interface->GetStockGraphicsSocket());

}

StockNode::StockNode(StockScene *stock_scene, std::string title,
                     StockSocketInterface* socket1)
{
    m_stock_graphics_node = new StockGraphicsNode(this,title);
    m_stock_socket_interface = socket1;
    m_stock_socket_interface->GetStockGraphicsSocket()->setParentItem(m_stock_graphics_node);
    stock_scene->AddNode(this);
    stock_scene->GetGraphicsScenePtr()->addItem(m_stock_graphics_node);
}

StockGraphicsNode *StockNode::GetStockGraphicsNode()
{
    return m_stock_graphics_node;
}


QPointF StockNode::GetStockSocketPosition()
{
    return QPointF(100,100);
}

void StockNode::SetStockNodePosition(QPointF pos)
{
    m_stock_graphics_node->setPos(pos);
}

void StockNode::UpdateConnectedEdge()
{
    std::cout<<"update edges with related socket"<<std::endl;
    m_stock_socket_interface->GetStockEdge()->UpdatePositions();
}
