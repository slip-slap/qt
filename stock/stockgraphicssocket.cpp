#include "stockgraphicssocket.h"
#include <QGraphicsSceneMouseEvent>
#include <iostream>
StockGraphicsSocket::StockGraphicsSocket()
{
    this->setFlag(QGraphicsItem::ItemIsMovable);
}

StockGraphicsSocket::StockGraphicsSocket(StockSocketInterface *stock_socket)
{
    this->setFlag(QGraphicsItem::ItemIsMovable);
    this->m_stock_socket_interface = stock_socket;
}

StockSocketInterface *StockGraphicsSocket::GetStockSocketInterface()
{
    return m_stock_socket_interface;
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

