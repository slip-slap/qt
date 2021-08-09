#include "stocknode.h"



StockNode::StockNode(QGraphicsScene *scene, StockSocket *socket)
{
    m_stock_graphics_node = new StockGraphicsNode();
    m_stock_socket = new StockSocket(this);
    auto v=m_stock_socket->GetStockGraphicsSocket();
    v->setParentItem(m_stock_graphics_node);
    scene->addItem(m_stock_graphics_node);
    scene->addItem(v);
}

StockGraphicsNode *StockNode::GetStockGraphicsNode()
{
    return m_stock_graphics_node;
}

StockSocket *StockNode::GetStockSocket()
{
    return m_stock_socket;
}

QPointF StockNode::GetStockSocketPosition()
{
    return QPointF(100,100);
}
