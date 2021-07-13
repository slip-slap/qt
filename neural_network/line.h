#ifndef LINE_H
#define LINE_H

#include <QGraphicsItem>
#include <QLineF>
#include <QPainter>
#include <QRandomGenerator>

class Line: public QGraphicsItem
{
public:
    Line();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void advance(int phase);

public:
    QColor color;
    QLineF line;
};

#endif // LINE_H
