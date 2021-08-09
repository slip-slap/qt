#include "stockgraphicsnode.h"
#include <QPainterPath>


StockGraphicsNode::StockGraphicsNode(): QGraphicsItem()
{
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
    title->addRoundedRect(0,0,180,40,5,5);
    title->addText(0,0,QFont("Times",20),"Tencent");
    painter->drawPath(title->simplified());

    painter->setBrush(Qt::NoBrush);
    painter->drawRoundedRect(0,0,180,240,10,10);

}
