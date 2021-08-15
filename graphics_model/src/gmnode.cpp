#include "gmnode.h"
#include "gmsocket.h"
#include <iostream>
#include <string>
#include <sstream>

#include "json/json.hpp"

GMNode::GMNode(GMScene *scene)
{
    m_gm_scene = scene;
    m_gmqt_graphics_node = new GMQtGraphicsNode(this,"nothing");
    m_gmqt_socket_interface1= new GMSocket(this, POSITION::NORTH_ANCHOR);
    m_gmqt_socket_interface2= new GMSocket(this, POSITION::SOUTH_ANCHOR);
    m_gm_scene->AddNode(this);
}


GMQtGraphicsNode *GMNode::GetStockGraphicsNode()
{
    return m_gmqt_graphics_node;
}

GMScene *GMNode::GetGMScene()
{
    return m_gm_scene;
}

void GMNode::RemoveNode()
{
}

GMSocketInterface *GMNode::GetGMSocket(int pos)
{
    if(pos == POSITION::NORTH_ANCHOR){
        return m_gmqt_socket_interface1;
    }
    if(pos == POSITION::SOUTH_ANCHOR){
        return m_gmqt_socket_interface2;
    }
    return nullptr;
}


void GMNode::SetStockNodePosition(QPointF pos)
{
    m_gmqt_graphics_node->setPos(pos);
    //GMSocket* gm_socket = static_cast<GMSocket*>(m_gmqt_socket_interface1);
    //std::pair<double, double> pair = this->GetNorthAnchor();
    //gm_socket->SetPosition(pair);
    m_gmqt_graphics_node->update();
}

void GMNode::UpdateConnectedEdge()
{
    std::cout<<"update edges with related socket"<<std::endl;
    if(m_gmqt_socket_interface1!=nullptr){
       //update nodes
       std::vector<StockEdgeInterface*> relatedEdge = m_gmqt_socket_interface1->GetAllRelatedEdge();
       for(auto v:relatedEdge)
       {
           v->UpdatePositions();
       }
    }
    if(m_gmqt_socket_interface2!=nullptr){
        std::vector<StockEdgeInterface*> relatedEdge = m_gmqt_socket_interface2->GetAllRelatedEdge();
        for(auto v:relatedEdge)
        {
            v->UpdatePositions();
        }
    }
}

QPointF GMNode::GetStockNodePosition()
{
    return m_gmqt_graphics_node->pos();
}

std::pair<double, double> GMNode::GetNorthAnchor()
{
    double pos_x = m_gmqt_graphics_node->GetNodeStartX() + m_gmqt_graphics_node->GetNodeEndX();
    double pos_y = m_gmqt_graphics_node->GetNodeStartY();
    return std::make_pair(pos_x/2,pos_y);
}

std::pair<double, double> GMNode::GetSouthAnchor()
{
    double pos_x = m_gmqt_graphics_node->GetNodeStartX() + m_gmqt_graphics_node->GetNodeEndX();
    double pos_y = m_gmqt_graphics_node->GetNodeEndY();
    return std::make_pair(pos_x/2,pos_y);
}

std::pair<double, double> GMNode::GetWestAnchor()
{
    double pos_x = m_gmqt_graphics_node->GetNodeStartX();
    double pos_y = m_gmqt_graphics_node->GetNodeEndY()+ m_gmqt_graphics_node->GetNodeStartY();
    return std::make_pair(pos_x,pos_y/2);
}

std::pair<double, double> GMNode::GetEastAnchor()
{
    double pos_x = m_gmqt_graphics_node->GetNodeEndX();
    double pos_y = m_gmqt_graphics_node->GetNodeEndY()+ m_gmqt_graphics_node->GetNodeStartY();
    return std::make_pair(pos_x,pos_y/2);
}

std::pair<double, double> GMNode::GetAnchor(int pos)
{
    if(pos == POSITION::NORTH_ANCHOR){
        return GetNorthAnchor();
    }
    if(pos == POSITION::SOUTH_ANCHOR){
        return GetSouthAnchor();
    }
    if(pos == POSITION::WEST_ANCHOR){
        return GetWestAnchor();
    }
    if(pos == POSITION::EAST_ANCHOR){
        return GetEastAnchor();
    }
    return GetEastAnchor();
}

std::string GMNode::serialize()
{
    GMSocket* gm_socket1 = (GMSocket*)m_gmqt_socket_interface1;
    GMSocket* gm_socket2 = (GMSocket*)m_gmqt_socket_interface2;
    nlohmann::json js_socket;
    js_socket.push_back({js_socket.parse(gm_socket1->serialize())});
    js_socket.push_back({js_socket.parse(gm_socket2->serialize())});

    nlohmann::json js =
    {
        {"id", reinterpret_cast<std::uintptr_t>(this)},
        {"scene",reinterpret_cast<std::uintptr_t>(m_gm_scene)},
        {"pos_x",m_gmqt_graphics_node->pos().rx()},
        {"pos_y",m_gmqt_graphics_node->pos().ry()}
    };
    js["socket"] = js_socket;
    return js.dump();
}

GMObject* GMNode::deserialize(std::string data)
{
    std::stringstream ss; ss<<data;
    nlohmann::json js;    ss>>js;
    std::cout<<js.dump(4)<<std::endl;
    this->SetStockNodePosition(QPointF(js["pos_x"],js["pos_y"]));
    m_gm_scene->AddNode(this);


    return nullptr;
}

std::ostream& operator<<(std::ostream& out, const GMNode& obj)
{
    std::cout<<&obj<<std::endl;

    return out;
}
