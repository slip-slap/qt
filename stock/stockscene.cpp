#include "stockscene.h"
#include "stockgraphicsscene.h"

StockScene::StockScene()
{
    m_graphics_scene = new StockGraphicsScene();
}

void StockScene::AddNode(StockNodeInterface *stock_node)
{
    m_stock_node_interface_vec.push_back(stock_node);
}

void StockScene::AddEdge(StockEdgeInterface *stock_edge)
{
    m_stock_edge_interface_vec.push_back(stock_edge);
}

QGraphicsScene *StockScene::GetGraphicsScenePtr()
{
    return m_graphics_scene;
}
