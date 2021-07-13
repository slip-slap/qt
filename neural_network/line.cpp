#include "line.h"
#include <iostream>

Line::Line()
{
    //int x1 = QRandomGenerator::global()->bounded(1,255);
    //int y1 = QRandomGenerator::global()->bounded(1,255);
    //int x2 = QRandomGenerator::global()->bounded(1,255);
    //int y2 = QRandomGenerator::global()->bounded(1,255);
    line = QLineF(-100,-100,100,100);
}

QRectF Line::boundingRect() const
{
    return QRect(0,0, 20, 20);
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    std::cout<<line.p1().ry()<<std::endl;
    painter->drawLine(line);
}

void Line::advance(int phase)
{
    if(!phase) return;
    int x1 = QRandomGenerator::global()->bounded(-100,-50);
    int y1 = QRandomGenerator::global()->bounded(-200,-150);
    int x2 = QRandomGenerator::global()->bounded(-200,200);
    int y2 = QRandomGenerator::global()->bounded(50,100);

    //QPointF loc = this->pos();
   // setPos(mapToParent(0,0));
    line.setLine(x1,y1,x2, y2);

}
