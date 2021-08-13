#include "stockgraphicsscene.h"
#include "gmnode.h"
#include <iostream>
#include <QMenu>
#include <QPen>
#include <QGraphicsSceneContextMenuEvent>
#include <QGraphicsEllipseItem>
#include "gmqtgraphicssocket.h"



StockGraphicsScene::StockGraphicsScene(GMScene *gm_scene)
{
    m_gm_scene = gm_scene;
}

GMScene *StockGraphicsScene::GetGMScene()
{
    return m_gm_scene;
}


void StockGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent*event)
{
    QGraphicsScene::mouseMoveEvent(event);

}
