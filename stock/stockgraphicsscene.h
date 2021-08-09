#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H


#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>

class StockGraphicsScene: public QGraphicsScene
{
public:
    StockGraphicsScene();




protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

};

#endif // GRAPHICSSCENE_H
