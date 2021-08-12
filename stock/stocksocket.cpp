#include "stocksocket.h"


StockSocket::StockSocket()
{
    m_stock_graphics_socket = new StockGraphicsSocket(this);
}

StockSocket::StockSocket(StockNodeInterface *stock_node_interface)
{
    m_stock_graphics_socket = new StockGraphicsSocket(this);
    m_stock_node_interface = stock_node_interface;
    m_stock_graphics_socket->setPos(m_stock_node_interface->GetStockNodePosition());
}

StockGraphicsSocket *StockSocket::GetStockGraphicsSocket()
{
    return m_stock_graphics_socket;
}

QPointF StockSocket::GetSocketPosition()
{
    return m_stock_graphics_socket->mapToScene(0,0);
}

void StockSocket::SetStockNode(StockNodeInterface *stock_node)
{
    m_stock_node_interface = stock_node;
}


void StockSocket::AddRelatedEdge(StockEdgeInterface *stock_edge_interface)
{
    m_stock_edge_interface_vec.push_back(stock_edge_interface);
}

std::vector<StockEdgeInterface *> StockSocket::GetAllRelatedEdge()
{
    return m_stock_edge_interface_vec;
}

StockNodeInterface *StockSocket::GetStockNode()
{
    return m_stock_node_interface;
}

