#ifndef STOCKNODE_H
#define STOCKNODE_H


#include "StockSocketInterface.h"
#include "stocknodeinterface.h"
#include "stockgraphicsnode.h"
#include "stockscene.h"
#include <QGraphicsScene>
#include <string>

class StockNode: public StockNodeInterface
{
public:
    StockNode(QGraphicsScene* scene, StockSocketInterface* stock_socket_interface);

    StockNode(StockScene* stock_scene, std::string title,
              StockSocketInterface* socket1);
    StockNode(StockScene* stock_scene, std::string title,
              StockSocketInterface* socket1,
              StockSocketInterface* socket2);
    StockGraphicsNode *GetStockGraphicsNode();
    StockScene* GetStockScene();
    QPointF GetStockSocketPosition();

    StockSocketInterface *GetStockSocketInterface();
    void SetStockNodePosition(QPointF pos);

    void UpdateConnectedEdge() override;
    QPointF GetStockNodePosition() override;
private:
    StockGraphicsNode* m_stock_graphics_node;
    StockSocketInterface* m_stock_socket_interface1=nullptr;
    StockSocketInterface* m_stock_socket_interface2=nullptr;
    StockScene* m_stock_scene;
};

#endif // STOCKNODE_H
