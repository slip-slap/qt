#ifndef GRAPHICSEDGE_H
#define GRAPHICSEDGE_H

#include <QGraphicsPathItem>
#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>


class StockGraphicsEdge: public QGraphicsPathItem
{
public:
    StockGraphicsEdge();


public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    void SetSource(QPointF source);
    void SetTarget(QPointF target);

private:
    QPointF m_source;
    QPointF m_target;
};

#endif // GRAPHICSEDGE_H
