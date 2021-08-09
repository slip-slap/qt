#include "stocksocket.h"


StockSocket::StockSocket(StockNode *stock_node)
{
    m_stock_node = stock_node;
    m_stock_graphics_socket = new StockGraphicsSocket();
}

StockGraphicsSocket *StockSocket::GetStockGraphicsSocket()
{
    return m_stock_graphics_socket;
}

QPointF StockSocket::GetSocketPosition()
{

}
