#include "stockgraphicsedge.h"


StockGraphicsEdge::StockGraphicsEdge():QGraphicsPathItem()
{
    this->setFlag(QGraphicsItem::ItemIsSelectable,true);
}

QRectF StockGraphicsEdge::boundingRect() const
{
    return QRectF(0,0,200,200);
}

void StockGraphicsEdge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen = QPen(Qt::red);
    pen.setWidth(5);
    painter->setPen(pen);
    painter->setBrush(QBrush(Qt::red));
    QPainterPath path(m_source);
    path.lineTo(m_target);
    painter->drawPath(path);
}

void StockGraphicsEdge::SetSource(QPointF source)
{
    m_source = source;
    this->update();
}

void StockGraphicsEdge::SetTarget(QPointF target)
{
    m_target = target;
    this->update();
}
