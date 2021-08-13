#ifndef STOCKNODE_H
#define STOCKNODE_H


#include "StockSocketInterface.h"
#include "stocknodeinterface.h"
#include "gmqtgraphicsnode.h"
#include "gmscene.h"
#include <QGraphicsScene>
#include <string>

#include "gmobject.h"
#include "gmserializable.h"

class GMNode: public StockNodeInterface, public GMSerializable, public GMObject
{
public:
    GMNode(QGraphicsScene* scene, StockSocketInterface* stock_socket_interface);

    GMNode(GMScene* stock_scene, std::string title,
              StockSocketInterface* socket1);
    GMNode(GMScene* stock_scene, std::string title,
              StockSocketInterface* socket1,
              StockSocketInterface* socket2);
    GMQtGraphicsNode *GetStockGraphicsNode();
    GMScene* GetGMScene();
    QPointF GetStockSocketPosition();

    StockSocketInterface *GetStockSocketInterface();
    void SetStockNodePosition(QPointF pos);

    void UpdateConnectedEdge() override;
    QPointF GetStockNodePosition() override;


public:
    std::string serialize() override;
    GMObject deserialize(std::string str) override;
    friend std::ostream& operator<<(std::ostream& out, const GMNode& obj);
private:
    GMQtGraphicsNode* m_stock_graphics_node;
    StockSocketInterface* m_stock_socket_interface1=nullptr;
    StockSocketInterface* m_stock_socket_interface2=nullptr;
    GMScene* m_gm_scene;
};

#endif // STOCKNODE_H
