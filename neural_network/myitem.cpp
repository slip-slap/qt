#include "myitem.h"
#include <iostream>
MyItem::MyItem(){
    speed = 0.1;
    setPos(mapToParent(1,1));
}

QRectF MyItem::boundingRect() const
{
    return QRect(0,0,20,20);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();

    QBrush Brush(Qt::gray);
    if(scene()->collidingItems(this).isEmpty())
    {
        Brush.setColor(Qt::green);
    }
    else
    {
        Brush.setColor(Qt::red);
        Docollision();
    }
    painter->drawRect(rec);
    painter->fillRect(rec,Brush);
}

void MyItem::advance(int phase)
{
    if(!phase) return;
    QPointF location = this->pos();
    //QPointF p = mapToParent(-0.1,0.1);
    //setPos(p);

}

void MyItem::Docollision()
{
    setRotation(rotation() + 96 + (rand()%10));
}
