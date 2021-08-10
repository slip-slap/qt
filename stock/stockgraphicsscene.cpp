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
    StockSocketInterface* socket1 = new StockSocket();
    StockSocketInterface* socket2 = new StockSocket();

    StockSocket* stocksocket1 = static_cast<StockSocket*>(socket1);
    StockSocket* stocksocket2 = static_cast<StockSocket*>(socket2);
    StockNode* node1 = new StockNode(this, socket1);
    node1->GetStockGraphicsNode()->setPos(500,0);
    stocksocket1->SetStockNode(node1);


    StockNode* node2 = new StockNode(this, socket2);
    node2->GetStockGraphicsNode()->setPos(100,0);
    stocksocket2->SetStockNode(node2);
    new StockEdge(this, stocksocket1, stocksocket2);
    //new StockEdge(this,node1->GetStockSocket(), node2->GetStockSocket());
}

StockGraphicsScene::StockGraphicsScene(StockScene *stock_scene)
{
    m_stock_scene = stock_scene;
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
