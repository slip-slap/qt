#include "stockedge.h"

StockEdge::StockEdge(StockScene *scene, StockSocketInterface *start_socket, StockSocketInterface *end_socket)
{
    m_scene = scene;
    m_start_socket = start_socket;
    m_end_socket = end_socket;
    m_edge = new StockGraphicsEdge();
    m_edge->SetSource(m_start_socket->GetSocketPosition()+QPointF(10,10));
    m_edge->SetTarget(m_end_socket->GetSocketPosition()+QPointF(10,10));
    // Add Related Edge to socket
    m_start_socket->AddRelatedEdge(this);
    m_end_socket->AddRelatedEdge(this);
    scene->GetGraphicsScenePtr()->addItem(m_edge);
    scene->AddEdge(this);
}


StockEdge::StockEdge(StockScene *scene, QPointF start, QPointF end)
{   m_scene = scene;
    m_edge = new StockGraphicsEdge();
    scene->GetGraphicsScenePtr()->addItem(m_edge);
    m_edge->SetSource(start);
    m_edge->SetTarget(end);
}

void StockEdge::SetTarget(QPointF des)
{
    if(m_edge!=nullptr){
        m_edge->SetTarget(des+QPointF(10,10));
        m_edge->update();
    }
}

void StockEdge::UpdatePositions()
{
    QPointF start = m_start_socket->GetSocketPosition();
    QPointF end=m_end_socket->GetSocketPosition();
    if(m_edge!=nullptr){
        m_edge->SetSource(start+QPointF(10,10));
        m_edge->SetTarget(end+QPointF(10,10));
        m_edge->update();
    }
}

void StockEdge::RemoveEdge()
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
    m_scene->GetGraphicsScenePtr()->removeItem(m_edge);
}
