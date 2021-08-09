#ifndef GRAPHICSEDGE_H
#define GRAPHICSEDGE_H

#include <QGraphicsPathItem>
#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>

class StockEdge;

class StockGraphicsEdge: public QGraphicsPathItem
{
public:
    StockGraphicsEdge(StockEdge* stockedge);


public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

private:
    StockEdge* m_stock_edge;
};

#endif // GRAPHICSEDGE_H
