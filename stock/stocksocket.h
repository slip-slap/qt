#ifndef STOCKSOCKET_H
#define STOCKSOCKET_H

#include "stockgraphicssocket.h"
class StockNode;


class StockSocket
{
public:
    StockSocket(StockNode* stock_node);
    StockGraphicsSocket *GetStockGraphicsSocket();
    QPointF GetSocketPosition();

private:
    StockNode* m_stock_node;
    StockGraphicsSocket* m_stock_graphics_socket;
};

#endif // STOCKSOCKET_H
