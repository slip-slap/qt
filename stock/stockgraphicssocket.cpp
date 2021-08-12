#include "stockgraphicssocket.h"
#include <QGraphicsSceneMouseEvent>
#include <iostream>
StockGraphicsSocket::StockGraphicsSocket()
{
    this->InitUI();
}

StockGraphicsSocket::StockGraphicsSocket(StockSocketInterface *stock_socket)
{
    this->InitUI();
    this->m_stock_socket_interface = stock_socket;
}

StockSocketInterface *StockGraphicsSocket::GetStockSocketInterface()
{
    return m_stock_socket_interface;
}

void StockGraphicsSocket::InitUI()
{
    this->setFlag(QGraphicsItem::ItemIsMovable);
    this->setFlag(QGraphicsItem::ItemIsSelectable);
}


QRectF StockGraphicsSocket::boundingRect() const
{
    return QRectF(0,0,20,20);
}

void StockGraphicsSocket::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(Qt::red));
    painter->setBrush(QColor(Qt::red));
    if(this->isSelected()){
        painter->setPen(QColor(Qt::yellow));
        painter->drawEllipse(0,0,21,21);
    }
    painter->drawEllipse(0,0,20,20);
}

