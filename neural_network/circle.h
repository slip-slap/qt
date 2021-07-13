#ifndef CIRCLE_H
#define CIRCLE_H

#include<QPainter>
#include<QGraphicsItem>

class Circle :public QGraphicsItem
{
public:
    Circle();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void advance(int phase);

};

#endif // CIRCLE_H
