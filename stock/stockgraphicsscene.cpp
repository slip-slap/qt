#include "stockgraphicsscene.h"
#include "stocknode.h"
#include <iostream>
#include <QMenu>
#include <QPen>
#include <QGraphicsSceneContextMenuEvent>
#include <QGraphicsEllipseItem>
#include "stockedge.h"
#include "stockgraphicssocket.h"
#include "stocksocket.h"
StockGraphicsScene::StockGraphicsScene(): QGraphicsScene()
{
}

StockGraphicsScene::StockGraphicsScene(StockScene *stock_scene)
{
    m_stock_scene = stock_scene;
}

StockScene *StockGraphicsScene::GetStockScene()
{
    return m_stock_scene;
}

void StockGraphicsScene::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu menu;
    QAction *removeAction = menu.addAction("Remove");
    QAction *addAction = menu.addAction("Add");
    menu.exec(event->screenPos());

    double x = event->scenePos().rx();
    double y = event->scenePos().ry();

    //QGraphicsEllipseItem* ellipse = this->addEllipse(x,y, 50,50,QPen(Qt::white));
    //ellipse->setFlag(QGraphicsItem::ItemIsMovable,true);
    //ellipse->setFlag(QGraphicsItem::ItemIsSelectable);

}

void StockGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent*event)
{
    QGraphicsScene::mouseMoveEvent(event);

}
