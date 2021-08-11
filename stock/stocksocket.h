#ifndef STOCKSOCKET_H
#define STOCKSOCKET_H

#include "stockgraphicssocket.h"
#include "stocknode.h"
#include "stockedge.h"

class StockSocket: public StockSocketInterface
{
public:
    StockSocket();
    StockGraphicsSocket *GetStockGraphicsSocket() override;
    QPointF GetSocketPosition() override;
    void SetStockNode(StockNodeInterface* stock_node) override;
    void SetStockEdge(StockEdgeInterface* stock_edge) override;
    StockNodeInterface* GetStockNode() override;
    StockEdgeInterface* GetStockEdge() override;

private:
    StockNodeInterface* m_stock_node_interface=nullptr;
    StockEdgeInterface* m_stock_edge_interface=nullptr;
    StockGraphicsSocket* m_stock_graphics_socket=nullptr;
};

#endif // STOCKSOCKET_H
