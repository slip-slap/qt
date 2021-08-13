#include "gmscene.h"
#include "stockgraphicsscene.h"
#include "gmedge.h"
#include "json/json.hpp"
#include <algorithm>

GMScene::GMScene()
{
    m_stock_graphics_scene = new StockGraphicsScene(this);
}

void GMScene::AddNode(StockNodeInterface *stock_node_interface)
{
   GMNode* stock_node = (GMNode*)stock_node_interface;
   m_stock_graphics_scene->addItem(stock_node->GetStockGraphicsNode());
   m_stock_node_interface_vec.push_back(stock_node);
}

void GMScene::AddEdge(StockEdgeInterface *stock_edge)
{
    m_stock_edge_interface_vec.push_back(stock_edge);
}

void GMScene::RemoveNode(StockNodeInterface *stock_node)
{
    m_stock_node_interface_vec.erase(std::remove
                                          (
                                            m_stock_node_interface_vec.begin(),
                                            m_stock_node_interface_vec.end(),
                                            stock_node),
                                      m_stock_node_interface_vec.end()
                                     );
}

void GMScene::RemoveEdge(StockEdgeInterface *stock_edge)
{
    //remove edge
    GMEdge* stock_edge_imp = static_cast<GMEdge*>(stock_edge);
    stock_edge_imp->RemoveEdge();
    m_stock_edge_interface_vec.erase(std::remove
                                          (
                                            m_stock_edge_interface_vec.begin(),
                                            m_stock_edge_interface_vec.end(),
                                            stock_edge),
                                      m_stock_edge_interface_vec.end()
                                     );

}

std::vector<StockNodeInterface *> GMScene::GetStockNodesVector()
{
    return m_stock_node_interface_vec;
}

std::vector<StockEdgeInterface *> GMScene::GetStockEdgesVector()
{
    return m_stock_edge_interface_vec;
}

QGraphicsScene* GMScene::GetGraphicsScenePtr()
{
    return m_stock_graphics_scene;
}

std::string GMScene::serialize()
{
    nlohmann::json js;
    for(auto i:m_stock_node_interface_vec){
        GMNode* stock_node = (GMNode*)i;
        js.push_back({"node",js.parse(stock_node->serialize())});
    }
    return js.dump();
}

GMObject GMScene::deserialize(std::string str)
{
    return GMObject();
}



