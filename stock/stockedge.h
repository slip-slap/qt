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
    void UpdatePositions();

private:
    StockGraphicsScene* m_scene;
    StockSocketInterface* m_start_socket;
    StockSocketInterface* m_end_socket;
    StockGraphicsEdge* m_edge;

};

#endif // STOCKEDGE_H
