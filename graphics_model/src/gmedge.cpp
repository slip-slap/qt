#include "gmedge.h"
#include "json/json.hpp"
#include <sstream>
#include <iostream>
GMEdge::GMEdge(GMScene *scene, GMSocketInterface *start_socket, GMSocketInterface *end_socket)
{
    m_gm_scene = scene;
    m_start_socket = start_socket;
    m_end_socket = end_socket;
    m_gmqt_edge = new GMQtGraphicsEdge();
    m_gmqt_edge->SetSource(m_start_socket->GetSocketPosition()+QPointF(10,10));
    m_gmqt_edge->SetTarget(m_end_socket->GetSocketPosition()+QPointF(10,10));
    // Add Related Edge to socket
    m_start_socket->AddRelatedEdge(this);
    m_end_socket->AddRelatedEdge(this);
    scene->GetGraphicsScenePtr()->addItem(m_gmqt_edge);
    scene->AddEdge(this);
}


GMEdge::GMEdge(GMScene *scene, QPointF start, QPointF end)
{   m_gm_scene = scene;
    m_gmqt_edge = new GMQtGraphicsEdge();
    scene->GetGraphicsScenePtr()->addItem(m_gmqt_edge);
    m_gmqt_edge->SetSource(start);
    m_gmqt_edge->SetTarget(end);
}

GMEdge::GMEdge(GMScene *scene, GMNode *node1, int pos1, GMNode *node2, int pos2)
{
    m_gm_scene = scene;
    m_start_socket = node1->GetGMSocket(pos1);
    m_end_socket = node2->GetGMSocket(pos2);
    m_gmqt_edge = new GMQtGraphicsEdge();
    m_gmqt_edge->SetSource(m_start_socket->GetSocketPosition()+QPointF(10,10));
    m_gmqt_edge->SetTarget(m_end_socket->GetSocketPosition()+QPointF(10,10));
    // Add Related Edge to socket
    m_start_socket->AddRelatedEdge(this);
    m_end_socket->AddRelatedEdge(this);
    m_gm_scene->GetGraphicsScenePtr()->addItem(m_gmqt_edge);
    m_gm_scene->AddEdge(this);
}

GMEdge::GMEdge(GMScene *scene)
{
    m_gm_scene = scene;
    m_gmqt_edge = new GMQtGraphicsEdge();
}

void GMEdge::SetTarget(QPointF des)
{
    if(m_gmqt_edge!=nullptr){
        m_gmqt_edge->SetTarget(des+QPointF(10,10));
        m_gmqt_edge->update();
    }
}

std::pair<double, double> GMEdge::GetSource()
{
    return std::make_pair(m_gmqt_edge->GetSource().rx(),m_gmqt_edge->GetSource().ry());
}

std::pair<double, double> GMEdge::GetTarget()
{
    return std::make_pair(m_gmqt_edge->GetTarget().rx(),m_gmqt_edge->GetTarget().ry());
}

void GMEdge::UpdatePositions()
{
    QPointF start = m_start_socket->GetSocketPosition();
    QPointF end=m_end_socket->GetSocketPosition();
    if(m_gmqt_edge!=nullptr){
        m_gmqt_edge->SetSource(start+QPointF(10,10));
        m_gmqt_edge->SetTarget(end+QPointF(10,10));
        m_gmqt_edge->update();
    }
}

void GMEdge::RemoveEdge()
{
    //Find Stock Socket Related to this edge, and remove reference to this edge
    if(m_start_socket!=nullptr)
    {
        std::vector<StockEdgeInterface*> related_edges = m_start_socket->GetAllRelatedEdge();
        related_edges.erase(std::remove(related_edges.begin(),related_edges.end(),this),related_edges.end());
    }
    if(m_end_socket!=nullptr)
    {
        std::vector<StockEdgeInterface*> related_edges = m_end_socket->GetAllRelatedEdge();
        related_edges.erase(std::remove(related_edges.begin(),related_edges.end(),this),related_edges.end());
    }
    //Remove edges from the scene
    m_gm_scene->GetGraphicsScenePtr()->removeItem(m_gmqt_edge);
}

void GMEdge::ConnectGMNodes(GMScene* scene, GMNode *node1, int pos1, GMNode *node2, int pos2)
{

    m_gm_scene = scene;
    m_start_socket = node1->GetGMSocket(POSITION::SOUTH_ANCHOR);
    m_end_socket = node2->GetGMSocket(POSITION::NORTH_ANCHOR);
    m_gmqt_edge = new GMQtGraphicsEdge();
    m_gmqt_edge->SetSource(m_start_socket->GetSocketPosition()+QPointF(10,10));
    m_gmqt_edge->SetTarget(m_end_socket->GetSocketPosition()+QPointF(10,10));
    // Add Related Edge to socket
    m_start_socket->AddRelatedEdge(this);
    m_end_socket->AddRelatedEdge(this);
    m_gm_scene->GetGraphicsScenePtr()->addItem(m_gmqt_edge);
    m_gm_scene->AddEdge(this);
}

std::string GMEdge::serialize()
{
    //GMSocket* gm_socket1 = (GMSocket*)m_start_socket;
    //GMSocket* gm_socket2 = (GMSocket*)m_end_socket;

    nlohmann::json json_socket;
    json_socket.push_back({json_socket.parse(m_start_socket->serialize())});
    json_socket.push_back({json_socket.parse(m_end_socket->serialize())});
    nlohmann::json js =
    {
        {"id", reinterpret_cast<std::uintptr_t>(this)},
        {"scene",reinterpret_cast<std::uintptr_t>(m_gm_scene)},
        {"socket", json_socket}
    };
    return js.dump();
}

GMObject* GMEdge::deserialize(std::string str)
{
    std::stringstream ss;
    ss<<str;
    nlohmann::json js;
    ss>>js;
    std::cout<<js["socket"]<<std::endl;
    return nullptr;
}
