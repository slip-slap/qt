#ifndef STOCKSOCKETINTERFACE_H
#define STOCKSOCKETINTERFACE_H

#include <QGraphicsItem>
#include <QPointF>
#include "stocknodeinterface.h"
#include "stockedgeinterface.h"

class StockSocketInterface{
public:
    virtual QPointF GetSocketPosition()=0;
    virtual QGraphicsItem* GetStockGraphicsSocket()=0;
    virtual void SetStockNode(StockNodeInterface* stock_node_interface)=0;
    virtual void SetStockEdge(StockEdgeInterface* stock_edge_interface)=0;
    virtual StockNodeInterface* GetStockNode()=0;
    virtual StockEdgeInterface* GetStockEdge()=0;
};

#endif // STOCKSOCKETINTERFACE_H
