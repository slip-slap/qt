#ifndef STOCKSOCKET_H
#define STOCKSOCKET_H

#include "stockgraphicssocket.h"
#include "stocknode.h"
#include "stockedge.h"

class StockSocket: public StockSocketInterface
{
public:
    StockSocket();
    StockSocket(StockNodeInterface* stock_node_interface);
    StockGraphicsSocket *GetStockGraphicsSocket() override;
    QPointF GetSocketPosition() override;
    void SetStockNode(StockNodeInterface* stock_node) override;
    void AddRelatedEdge(StockEdgeInterface* stock_edge_interface) override;
    std::vector<StockEdgeInterface*> GetAllRelatedEdge() override;
    StockNodeInterface* GetStockNode() override;

private:
    StockNodeInterface* m_stock_node_interface=nullptr;
    StockEdgeInterface* m_stock_edge_interface=nullptr;
    StockGraphicsSocket* m_stock_graphics_socket=nullptr;
    // one to many
    std::vector<StockEdgeInterface*> m_stock_edge_interface_vec;
};

#endif // STOCKSOCKET_H
