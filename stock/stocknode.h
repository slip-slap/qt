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
    StockGraphicsNode *GetStockGraphicsNode();
    QPointF GetStockSocketPosition();
    void SetStockNodePosition(QPointF pos);

    void UpdateConnectedEdge() override;
private:
    StockGraphicsNode* m_stock_graphics_node;
    StockSocketInterface* m_stock_socket_interface;
};

#endif // STOCKNODE_H
