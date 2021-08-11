#include "stockedge.h"
StockEdge::StockEdge(StockGraphicsScene *scene, StockSocketInterface *start_socket,
                     StockSocketInterface *end_socket)
{
    /*m_scene = scene;
    m_start_socket = start_socket;
    m_end_socket = end_socket;
    m_edge = new StockGraphicsEdge();
    QPointF start = m_start_socket->GetSocketPosition();
    QPointF end=m_end_socket->GetSocketPosition();
    m_edge->SetSource(start);
    m_edge->SetTarget(end);
    m_scene->addItem(m_edge);*/

}

StockEdge::StockEdge(StockScene *scene, StockSocketInterface *start_socket, StockSocketInterface *end_socket)
{
    m_stock_scene = scene;
    m_start_socket = start_socket;
    m_end_socket = end_socket;
    m_edge = new StockGraphicsEdge();
    m_edge->SetSource(m_start_socket->GetSocketPosition()+QPointF(10,10));
    m_edge->SetTarget(m_end_socket->GetSocketPosition()+QPointF(10,10));
    m_start_socket->SetStockEdge(this);
    m_end_socket->SetStockEdge(this);
    m_stock_scene->GetGraphicsScenePtr()->addItem(m_edge);
    m_stock_scene->AddEdge(this);
}

StockEdge::StockEdge(StockScene *scene, StockSocketInterface *start_socket, QPointF pos)
{
    m_stock_scene = scene;
    m_start_socket = start_socket;
    m_edge = new StockGraphicsEdge();
    m_edge->SetSource(m_start_socket->GetSocketPosition()+QPointF(10,10));
    m_edge->SetTarget(pos+QPointF(10,10));
    m_start_socket->SetStockEdge(this);
    m_stock_scene->GetStockGraphicsScene()->addItem(m_edge);
    m_stock_scene->AddEdge(this);
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
