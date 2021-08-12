#include "stockgraphicscuttingline.h"
#include <QPen>
StockGraphicsCuttingLine::StockGraphicsCuttingLine()
{

}

StockGraphicsCuttingLine::StockGraphicsCuttingLine(StockGraphicsScene *stock_graphics_scene)
{
    stock_graphics_scene->addItem(this);
}

void StockGraphicsCuttingLine::AppendQPoint(QPoint point)
{
    m_qpoints.append(point);
}


QRectF StockGraphicsCuttingLine::boundingRect() const
{
    return QRectF(0,0,1,1);
}

void StockGraphicsCuttingLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                                     QWidget *widget)
{
    QPen pen(Qt::green);
    QVector<qreal> pattern{3,3};
    pen.setDashPattern(pattern);
    painter->setPen(pen);
    painter->drawPolyline(QPolygonF(m_qpoints));

}
