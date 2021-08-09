#ifndef STOCKNODE_H
#define STOCKNODE_H

#include "stockgraphicsnode.h"
#include "stocksocket.h"

#include <QGraphicsScene>

class StockNode
{
public:
    StockNode(QGraphicsScene* scene, StockSocket* socket);
    StockGraphicsNode *GetStockGraphicsNode();
    StockSocket* GetStockSocket();
    QPointF GetStockSocketPosition();
private:
    StockGraphicsNode* m_stock_graphics_node;
    StockSocket* m_stock_socket;
};

#endif // STOCKNODE_H
