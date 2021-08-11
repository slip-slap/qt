#include "stocksocket.h"


StockSocket::StockSocket()
{
    m_stock_graphics_socket = new StockGraphicsSocket(this);
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

void StockSocket::SetStockEdge(StockEdgeInterface *stock_edge)
{
    m_stock_edge_interface = stock_edge;
}

StockNodeInterface *StockSocket::GetStockNode()
{
    return m_stock_node_interface;
}

StockEdgeInterface *StockSocket::GetStockEdge()
{
    return m_stock_edge_interface;
}
