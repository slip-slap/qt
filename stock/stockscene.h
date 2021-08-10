#ifndef STOCKSCENE_H
#define STOCKSCENE_H

#include <QGraphicsScene>
#include <vector>
#include <stocknodeinterface.h>
#include <stockedgeinterface.h>

class StockScene
{
public:
    StockScene();
    void AddNode(StockNodeInterface* stock_node);
    void AddEdge(StockEdgeInterface* stock_edge);
    void RemoveNode();
    void RemoveEdge();
    QGraphicsScene *GetGraphicsScenePtr();

private:
    QGraphicsScene* m_graphics_scene;
    std::vector<StockNodeInterface*> m_stock_node_interface_vec;
    std::vector<StockEdgeInterface*> m_stock_edge_interface_vec;
};

#endif // STOCKSCENE_H