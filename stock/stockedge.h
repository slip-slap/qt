#ifndef STOCKEDGE_H
#define STOCKEDGE_H

#include "stockgraphicsscene.h"
#include "StockSocketInterface.h"
#include "stockgraphicsedge.h"
#include "stockscene.h"
#include "stockedgeinterface.h"
class StockEdge: public StockEdgeInterface
{
public:
    StockEdge(StockGraphicsScene* scene, StockSocketInterface* start_socket, StockSocketInterface* end_socket);
    StockEdge(StockScene* scene, StockSocketInterface* start_socket, StockSocketInterface* end_socket);
    StockEdge(StockScene* scene, StockSocketInterface* start_socket, QPointF pos);
    void SetTarget(QPointF des);
    void UpdatePositions();

private:
    StockGraphicsScene* m_scene=nullptr;
    StockSocketInterface* m_start_socket=nullptr;
    StockSocketInterface* m_end_socket=nullptr;
    StockGraphicsEdge* m_edge=nullptr;

};

#endif // STOCKEDGE_H
