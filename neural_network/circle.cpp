#include "circle.h"

Circle::Circle()
{

}

QRectF Circle::boundingRect() const
{
    return QRect(0,0,20,20);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();

    QBrush Brush(Qt::white);
    painter->setPen(QColor(255,255,255,255));
    painter->drawEllipse(rec);
}

void Circle::advance(int phase)
{

}
