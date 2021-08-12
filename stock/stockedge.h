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
    StockEdge(StockScene* scene, StockSocketInterface* start_socket, StockSocketInterface* end_socket);
    StockEdge(StockScene *scene, QPointF start, QPointF end);
    void SetTarget(QPointF des);
    void UpdatePositions();
    void RemoveEdge();

private:
    StockScene* m_scene=nullptr;
    StockSocketInterface* m_start_socket=nullptr;
    StockSocketInterface* m_end_socket=nullptr;
    StockGraphicsEdge* m_edge=nullptr;



};

#endif // STOCKEDGE_H
