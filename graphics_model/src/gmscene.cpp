#include "gmscene.h"
#include "gmqtgraphicsscene.h"
#include "gmedge.h"
#include "json/json.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
GMScene::GMScene()
{
    m_stock_graphics_scene = new GMQtGraphicScene(this);
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

void GMScene::RemoveNode(StockNodeInterface *gm_node)
{
    //remove edge
    GMNode* gm_node_imp = static_cast<GMNode*>(gm_node);
    m_stock_graphics_scene->removeItem(gm_node_imp->GetStockGraphicsNode());
    m_stock_node_interface_vec.erase(std::remove
                                          (
                                            m_stock_node_interface_vec.begin(),
                                            m_stock_node_interface_vec.end(),
                                            gm_node),
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

void GMScene::RemoveAllEdges()
{
    for(auto i:m_stock_edge_interface_vec){
        RemoveEdge(i);
    }
}

void GMScene::RemoveAllNodes()
{
    for(auto i:m_stock_node_interface_vec){
        RemoveNode(i);
    }
}

void GMScene::ClearScene()
{

    //first remove edge
    RemoveAllEdges();
    //then remove node
    RemoveAllNodes();
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

    // save the scene
    js["scene_id"] = reinterpret_cast<std::uintptr_t>(this);
    js["scene_width"] = m_stock_graphics_scene->width();
    js["scene_height"] = m_stock_graphics_scene->height();
    //save node
    nlohmann::json js_node;
    for(auto i:m_stock_node_interface_vec){
        GMNode* stock_node = (GMNode*)i;
        js_node.push_back({js_node.parse(stock_node->serialize())});
    }
    js["node"] = js_node;
    // edge
    nlohmann::json js_edge;
    for(auto i:m_stock_edge_interface_vec){
        GMEdge* stock_edge = (GMEdge*)i;
        js_edge.push_back({js_node.parse(stock_edge->serialize())});
    }
    js["edge"] = js_edge;
    return js.dump();
}

GMObject* GMScene::deserialize(std::string str)
{
    std::stringstream ss; ss<<str;
    nlohmann::json js;    ss>>js;
    //deserialize socket
    for(int i=0; i < js["node"].size(); i++)
    {
        GMNode* gm_node = new GMNode(this);
        gm_node->deserialize(js["node"][i].dump());
    }



    return nullptr;
}



