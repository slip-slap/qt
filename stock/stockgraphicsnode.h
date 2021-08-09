#ifndef GRAPHICSNODE_H
#define GRAPHICSNODE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>



class StockGraphicsNode: public QGraphicsItem
{
public:
    StockGraphicsNode();

public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

};

#endif // GRAPHICSNODE_H
