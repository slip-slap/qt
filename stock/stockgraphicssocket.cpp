#include "stockgraphicssocket.h"
#include <QGraphicsSceneMouseEvent>
#include <iostream>
StockGraphicsSocket::StockGraphicsSocket()
{
    this->setFlag(QGraphicsItem::ItemIsMovable);
}


QRectF StockGraphicsSocket::boundingRect() const
{
    return QRectF(0,0,20,20);
}

void StockGraphicsSocket::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(Qt::red));
    painter->setBrush(QColor(Qt::red));
    painter->drawEllipse(0,0,20,20);
}

