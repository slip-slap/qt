#ifndef STOCKEDGE_H
#define STOCKEDGE_H

#include "stockgraphicsscene.h"
#include "stocksocket.h"
#include "stockgraphicsedge.h"

class StockEdge
{
public:
    StockEdge(StockGraphicsScene* scene, StockSocket* start_socket, StockSocket* end_socket);
    void UpdatePosition();

private:
    StockGraphicsScene* m_scene;
    StockSocket* m_start_socket;
    StockSocket* m_end_socket;
    StockGraphicsEdge* m_edge;

};

#endif // STOCKEDGE_H
