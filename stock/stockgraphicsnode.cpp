#include "stockgraphicsnode.h"
#include <QPainterPath>


StockGraphicsNode::StockGraphicsNode(): QGraphicsItem()
{  
    this->setFlag(QGraphicsItem::ItemIsSelectable);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFlag(QGraphicsItem::ItemIsMovable);
}

StockGraphicsNode::StockGraphicsNode(std::string title)
{
    this->setFlag(QGraphicsItem::ItemIsSelectable);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFlag(QGraphicsItem::ItemIsMovable);
    m_title = title;
}

StockGraphicsNode::StockGraphicsNode(StockNodeInterface *stock_node_interface, std::string title)
{
    m_stock_node_interface = stock_node_interface;
    m_title = title;
    this->setFlag(QGraphicsItem::ItemIsSelectable);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFlag(QGraphicsItem::ItemIsMovable);
}

QRectF StockGraphicsNode::boundingRect() const
{
    return QRectF(0,0,200,200);
}

void StockGraphicsNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(Qt::NoBrush);
    QPainterPath* title = new QPainterPath();

    title->setFillRule(Qt::WindingFill);
    title->addRoundedRect(0,0,90,20,5,5);
    title->addText(0,0,QFont("Times",20),"Tencent");
    title->addText(80,0,QFont("Times",20),m_title.c_str());
    painter->drawPath(title->simplified());

    painter->setBrush(Qt::NoBrush);
    painter->drawRoundedRect(0,0,90,120,10,10);

}

void StockGraphicsNode::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
    m_stock_node_interface->UpdateConnectedEdge();
}
