#include "stockedge.h"
StockEdge::StockEdge(StockGraphicsScene *scene, StockSocketInterface *start_socket,
                     StockSocketInterface *end_socket)
{
    m_scene = scene;
    m_start_socket = start_socket;
    m_end_socket = end_socket;
    m_edge = new StockGraphicsEdge();
    QPointF start = m_start_socket->GetSocketPosition();
    QPointF end=m_end_socket->GetSocketPosition();
    m_edge->SetSource(start);
    m_edge->SetTarget(end);
    m_scene->addItem(m_edge);

}

StockEdge::StockEdge(StockScene *scene, StockSocketInterface *start_socket, StockSocketInterface *end_socket)
{

    m_start_socket = start_socket;
    m_end_socket = end_socket;
    m_edge = new StockGraphicsEdge();
    m_edge->SetSource(m_start_socket->GetSocketPosition());
    m_edge->SetTarget(m_end_socket->GetSocketPosition());
    m_start_socket->SetStockEdge(this);
    m_end_socket->SetStockEdge(this);
    scene->GetGraphicsScenePtr()->addItem(m_edge);
    scene->AddEdge(this);
}

void StockEdge::UpdatePositions()
{
    QPointF start = m_start_socket->GetSocketPosition();
    QPointF end=m_end_socket->GetSocketPosition();
    m_edge->SetSource(start);
    m_edge->SetTarget(end);
    m_edge->update();
}
