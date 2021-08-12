#ifndef STOCKSCENE_H
#define STOCKSCENE_H

#include <QGraphicsScene>
#include <vector>
#include "stocksceneinterface.h"
#include "stocknodeinterface.h"
#include "stockedgeinterface.h"

class StockScene
{
public:
    StockScene();
    void AddNode(StockNodeInterface* stock_node);
    void AddEdge(StockEdgeInterface* stock_edge);
    void RemoveNode();
    void RemoveEdge();
    std::vector<StockNodeInterface*> GetStockNodesVector();
    std::vector<StockEdgeInterface*> GetStockEdgesVector();
    QGraphicsScene *GetGraphicsScenePtr();

private:
    QGraphicsScene* m_stock_graphics_scene=nullptr;
    std::vector<StockNodeInterface*> m_stock_node_interface_vec;
    std::vector<StockEdgeInterface*> m_stock_edge_interface_vec;
};

#endif // STOCKSCENE_H
