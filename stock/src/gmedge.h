#ifndef STOCKEDGE_H
#define STOCKEDGE_H

#include "gmqtgraphicsscene.h"
#include "StockSocketInterface.h"
#include "gmqtgraphicsedge.h"
#include "gmscene.h"
#include "stockedgeinterface.h"
class GMEdge: public StockEdgeInterface
{
public:
    GMEdge(GMScene* scene, StockSocketInterface* start_socket, StockSocketInterface* end_socket);
    GMEdge(GMScene* scene, QPointF start, QPointF end);
    void SetTarget(QPointF des);
    void UpdatePositions();
    void RemoveEdge();

private:
    GMScene* m_scene=nullptr;
    StockSocketInterface* m_start_socket=nullptr;
    StockSocketInterface* m_end_socket=nullptr;
    GMQtGraphicsEdge* m_edge=nullptr;



};

#endif // STOCKEDGE_H
