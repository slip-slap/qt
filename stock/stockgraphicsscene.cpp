#include "stockgraphicsscene.h"
#include "stocknode.h"
#include <iostream>
#include <QMenu>
#include <QPen>
#include <QGraphicsSceneContextMenuEvent>
#include <QGraphicsEllipseItem>
#include "stockedge.h"

StockGraphicsScene::StockGraphicsScene(): QGraphicsScene()
{
    StockNode* node1 = new StockNode(this,nullptr);
    node1->GetStockGraphicsNode()->setPos(500,0);
    StockNode* node2 = new StockNode(this,nullptr);
    new StockEdge(this,node1->GetStockSocket(), node2->GetStockSocket());
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

    //std::cout<<"my node x: "<<m_node->GetGraphicsNode()->mapToScene(0,80).rx()<<std::endl;
    //std::cout<<"my node y: "<<m_node->GetGraphicsNode()->mapToScene(0,80).ry()<<std::endl;
    //std::cout<<"context menu"<<std::endl;

}
