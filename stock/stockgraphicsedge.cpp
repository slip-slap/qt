#include "stockgraphicsedge.h"


StockGraphicsEdge::StockGraphicsEdge(StockEdge *stock_edge):QGraphicsPathItem()
{
    m_stock_edge = stock_edge;
}

QRectF StockGraphicsEdge::boundingRect() const
{
    return QRectF(0,0,200,200);
}

void StockGraphicsEdge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::yellow);
    QPainterPath path(QPointF(0,0));
    path.lineTo(QPointF(100,100));
    painter->drawPath(path);
}
