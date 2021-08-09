#ifndef GRAPHICSSOCKET_H
#define GRAPHICSSOCKET_H

#include <QGraphicsItem>
#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>



class StockGraphicsSocket:public QGraphicsItem
{
public:
    StockGraphicsSocket();

public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
};

#endif // GRAPHICSSOCKET_H
