#ifndef GMScene_H
#define GMScene_H

#include <QGraphicsScene>
#include <vector>
#include "stocksceneinterface.h"
#include "stocknodeinterface.h"
#include "stockedgeinterface.h"
#include "gmobject.h"
#include "gmserializable.h"

class GMScene: public GMObject, public GMSerializable
{
public:
    GMScene();
    void AddNode(StockNodeInterface* stock_node);
    void AddEdge(StockEdgeInterface* stock_edge);
    void RemoveNode(StockNodeInterface* stock_node);
    void RemoveEdge(StockEdgeInterface* stock_edge);
    void RemoveAllEdges();
    void RemoveAllNodes();
    void ClearScene();
    std::vector<StockNodeInterface*> GetStockNodesVector();
    std::vector<StockEdgeInterface*> GetStockEdgesVector();
    QGraphicsScene *GetGraphicsScenePtr();

public:
    std::string serialize() override;
    GMObject deserialize(std::string str) override;

private:
    QGraphicsScene* m_stock_graphics_scene=nullptr;
    std::vector<StockNodeInterface*> m_stock_node_interface_vec;
    std::vector<StockEdgeInterface*> m_stock_edge_interface_vec;
};

#endif // GMScene_H
