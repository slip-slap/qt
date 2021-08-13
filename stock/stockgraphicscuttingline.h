#ifndef STOCKGRAPHICSCUTTINGLINE_H
#define STOCKGRAPHICSCUTTINGLINE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <string>
#include <QGraphicsSceneMouseEvent>
#include "stockgraphicsscene.h"

class StockGraphicsCuttingLine: public QGraphicsItem
{
public:
    StockGraphicsCuttingLine();
    StockGraphicsCuttingLine(StockGraphicsScene* stock_graphics_scene);
    void AppendQPoint(QPoint point);
    void ClearPoint();

public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

private:
    QVector<QPoint> m_qpoints;
};

#endif // STOCKGRAPHICSCUTTINGLINE_H
