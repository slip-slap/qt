#include "neuralnetwork.h"
#include <iostream>

NeuralNetwork::NeuralNetwork()
{
    number_of_layer = 7;
    nodes_each_layer={5,10,4,8,3,10,2};
    int startPosx = 0;
    int startPosy = 0;
    int scene_weight = 350;
    int scene_height = 250;
    int column_distance = scene_weight/number_of_layer;


    for(int i = 0;i < number_of_layer; i++){
        std::vector<Circle*> circleVector;
        for (int k = 0;k < nodes_each_layer[i]; k++){
            Circle *circle = new Circle();
            startPosy = startPosy + scene_height/(nodes_each_layer[i]+1.5);
            circle->setPos(startPosx,startPosy);
            circleVector.push_back(circle);
            vector_of_circle.push_back(circle);
        }
        startPosx = startPosx + column_distance;
        startPosy = 0;
        vector_of_circle_vector.push_back(circleVector);
     }

    std::vector<std::vector<Circle*>>::iterator itr0=vector_of_circle_vector.begin();
    for(int i=0;i<number_of_layer-1;i++){
        std::vector<Circle*> previous_column = *itr0;
        itr0++;
        std::vector<Circle*> current_column = *itr0;
        for (std::vector<Circle*>::iterator itr = current_column.begin(); itr != current_column.end();itr++){
            for(std::vector<Circle*>::iterator itr_pre = previous_column.begin(); itr_pre != previous_column.end(); itr_pre++){

                QLineF line0((*itr_pre)->pos().rx()+10,(*itr_pre)->pos().ry()+10,(*itr)->pos().rx()+10,(*itr)->pos().ry()+10);
                vector_of_qlinef.push_back(line0);
                int r = QRandomGenerator::global()->bounded(1,255);
                int g = QRandomGenerator::global()->bounded(1,255);
                int b = QRandomGenerator::global()->bounded(1,255);
                int alpha = QRandomGenerator::global()->bounded(1,255);
                vector_of_tuple.push_back(std::make_tuple(line0,QColor(r, g, b, alpha)));
            }
        }
    }
}

QRectF NeuralNetwork::boundingRect() const
{
    return QRect(0,0,2,2);
}

void NeuralNetwork::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //std::cout<<"change color"<<std::endl;
    QRectF rec = boundingRect();

    QBrush Brush(Qt::gray);
    Brush.setColor(Qt::red);
    for(std::vector<std::tuple<QLineF,QColor>>::iterator itr= vector_of_tuple.begin(); itr!=vector_of_tuple.end();itr++){
        painter->setPen(std::get<1>(*itr));
        painter->drawLine(std::get<0>(*itr));
    }
    painter->drawRect(rec);
    painter->fillRect(rec,Brush);
}

void NeuralNetwork::advance(int phase)
{
    //std::cout<<"advance "<<std::endl;
    if(!phase) return;
    for(std::vector<std::tuple<QLineF,QColor>>::iterator itr= vector_of_tuple.begin(); itr!=vector_of_tuple.end();itr++){
        int r = QRandomGenerator::global()->bounded(1,255);
        int g = QRandomGenerator::global()->bounded(1,255);
        int b = QRandomGenerator::global()->bounded(1,255);
        int alpha = QRandomGenerator::global()->bounded(1,255);
        std::get<1>(*itr).setRed(r);
        std::get<1>(*itr).setRed(g);
        std::get<1>(*itr).setRed(b);
        std::get<1>(*itr).setRed(alpha);
    }

}
