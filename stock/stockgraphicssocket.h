#ifndef GRAPHICSSOCKET_H
#define GRAPHICSSOCKET_H

#include <QGraphicsItem>
#include <QPainter>
#include <QWidget>
#include <QStyleOptionGraphicsItem>

#include "StockSocketInterface.h"

class StockGraphicsSocket:public QGraphicsItem
{
public:
    StockGraphicsSocket();
    StockGraphicsSocket(StockSocketInterface* stock_socket);
    StockSocketInterface* GetStockSocketInterface();

private:
    void InitUI();

public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
private:
    StockSocketInterface* m_stock_socket_interface;
};

#endif // GRAPHICSSOCKET_H
