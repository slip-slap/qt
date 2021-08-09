#include "stockedge.h"

StockEdge::StockEdge(StockGraphicsScene *scene, StockSocket *start_socket, StockSocket *end_socket)
{
    m_scene = scene;
    m_start_socket = start_socket;
    m_end_socket = end_socket;
    m_edge = new StockGraphicsEdge(this);
    m_scene->addItem(m_edge);

}

void StockEdge::UpdatePosition()
{

}
