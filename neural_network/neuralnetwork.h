#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "circle.h"

#include <vector>
#include <QGraphicsScene>
#include <QLineF>
#include <QRandomGenerator>

class NeuralNetwork: public QGraphicsItem
{
public:
    NeuralNetwork();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void advance(int phase);

public:
    std::vector<std::vector<Circle*>> vector_of_circle_vector;
    std::vector<QLineF> vector_of_qlinef;
    std::vector<std::tuple<QLineF,QColor>> vector_of_tuple;
    std::vector<Circle*> vector_of_circle;
    std::vector<int> nodes_each_layer;
    int number_of_layer;
};

#endif // NEURALNETWORK_H
