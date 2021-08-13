#include "gmnode.h"
#include "gmsocket.h"
#include <iostream>
#include "json/json.hpp"

GMNode::GMNode(QGraphicsScene *scene, StockSocketInterface* stock_socket_interface)
{
    m_stock_socket_interface1 = stock_socket_interface;
    m_stock_graphics_node = new GMQtGraphicsNode();
    m_stock_socket_interface1->GetStockGraphicsSocket()->setParentItem(m_stock_graphics_node);
    scene->addItem(m_stock_graphics_node);
    scene->addItem(m_stock_socket_interface1->GetStockGraphicsSocket());

}

GMNode::GMNode(GMScene *stock_scene, std::string title,
                     StockSocketInterface* socket1)
{
    m_stock_graphics_node = new GMQtGraphicsNode(this,title);
    m_stock_socket_interface1 = socket1;
    //m_stock_socket_interface = new StockSocket(this);
    m_stock_socket_interface1->GetStockGraphicsSocket()->setPos(m_stock_graphics_node->pos()+ QPointF(80,0));
    m_stock_socket_interface1->GetStockGraphicsSocket()->setParentItem(m_stock_graphics_node);
    stock_scene->AddNode(this);

}

GMNode::GMNode(GMScene *stock_scene, std::string title, StockSocketInterface *socket1, StockSocketInterface *socket2)
{
    m_gm_scene = stock_scene;
    m_stock_graphics_node = new GMQtGraphicsNode(this,title);
    m_stock_socket_interface1= socket1;
    m_stock_socket_interface2= socket2;
    //m_stock_socket_interface = new StockSocket(this);
    m_stock_socket_interface1->GetStockGraphicsSocket()->setPos(m_stock_graphics_node->pos()+ QPointF(40,0));
    m_stock_socket_interface1->GetStockGraphicsSocket()->setParentItem(m_stock_graphics_node);
    m_stock_socket_interface2->GetStockGraphicsSocket()->setPos(m_stock_graphics_node->pos()+ QPointF(40,90));
    m_stock_socket_interface2->GetStockGraphicsSocket()->setParentItem(m_stock_graphics_node);
    stock_scene->AddNode(this);
}

GMQtGraphicsNode *GMNode::GetStockGraphicsNode()
{
    return m_stock_graphics_node;
}

GMScene *GMNode::GetGMScene()
{
    return m_gm_scene;
}


QPointF GMNode::GetStockSocketPosition()
{
    return QPointF(100,100);
}

StockSocketInterface *GMNode::GetStockSocketInterface()
{
    return m_stock_socket_interface1;
}

void GMNode::SetStockNodePosition(QPointF pos)
{
    m_stock_graphics_node->setPos(pos);
}

void GMNode::UpdateConnectedEdge()
{
    std::cout<<"update edges with related socket"<<std::endl;
    if(m_stock_socket_interface1!=nullptr){
       std::vector<StockEdgeInterface*> relatedEdge = m_stock_socket_interface1->GetAllRelatedEdge();
       for(auto v:relatedEdge)
       {
           v->UpdatePositions();
       }
    }
    if(m_stock_socket_interface2!=nullptr){
        std::vector<StockEdgeInterface*> relatedEdge = m_stock_socket_interface2->GetAllRelatedEdge();
        for(auto v:relatedEdge)
        {
            v->UpdatePositions();
        }
    }
}

QPointF GMNode::GetStockNodePosition()
{
    return m_stock_graphics_node->pos();
}

std::string GMNode::serialize()
{
    double long id = reinterpret_cast<std::uintptr_t>(this);
    double long scene_id = reinterpret_cast<std::uintptr_t>(m_gm_scene);
    GMSocket* gm_socket1 = (GMSocket*)m_stock_socket_interface1;
    GMSocket* gm_socket2 = (GMSocket*)m_stock_socket_interface2;
    nlohmann::json js =
    {
        {"id", id},
        {"scene",scene_id},
        {"socket1", js.parse(gm_socket1->serialize())},
        {"socket2", js.parse(gm_socket1->serialize())}
    };

    return js.dump();
}

GMObject GMNode::deserialize(std::string data)
{
    return GMObject();
}

std::ostream& operator<<(std::ostream& out, const GMNode& obj)
{
    std::cout<<&obj<<std::endl;

    return out;
}
