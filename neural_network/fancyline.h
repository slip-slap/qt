#ifndef FANCYLINE_H
#define FANCYLINE_H

#include <QGraphicsLineItem>

class FancyLine: public QGraphicsLineItem
{
public:
    FancyLine(qreal x1, qreal y1, qreal x2, qreal y2, G);
};

#endif // FANCYLINE_H
