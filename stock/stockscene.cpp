#include "stockscene.h"
#include "stockgraphicsscene.h"

StockScene::StockScene()
{
    m_stock_graphics_scene = new StockGraphicsScene();
}

void StockScene::AddNode(StockNodeInterface *stock_node_interface)
{
   StockNode* stock_node = (StockNode*)stock_node_interface;
   m_stock_graphics_scene->addItem(stock_node->GetStockGraphicsNode());
   m_stock_node_interface_vec.push_back(stock_node);
}

void StockScene::AddEdge(StockEdgeInterface *stock_edge)
{
    m_stock_edge_interface_vec.push_back(stock_edge);
}

std::vector<StockNodeInterface *> StockScene::GetStockNodesVector()
{
    return m_stock_node_interface_vec;
}

std::vector<StockEdgeInterface *> StockScene::GetStockEdgesVector()
{
    return m_stock_edge_interface_vec;
}

QGraphicsScene* StockScene::GetGraphicsScenePtr()
{
    return m_stock_graphics_scene;
}

