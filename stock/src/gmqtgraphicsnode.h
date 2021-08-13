#ifndef GRAPHICSNODE_H
#define GRAPHICSNODE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <string>
#include <QGraphicsSceneMouseEvent>
#include "stocknodeinterface.h"

class GMQtGraphicsNode: public QGraphicsItem
{
public:
    GMQtGraphicsNode();
    GMQtGraphicsNode(std::string title);
    GMQtGraphicsNode(StockNodeInterface* stock_node_interface,std::string title);
private:
    void InitUI();

public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
private:
    std::string m_title;
    StockNodeInterface* m_stock_node_interface;
};

#endif // GRAPHICSNODE_H
