#ifndef STOCKSOCKET_H
#define STOCKSOCKET_H

#include "gmqtgraphicssocket.h"
#include "gmnode.h"
#include "gmedge.h"
#include "gmobject.h"
#include "gmserializable.h"

class GMSocket: public GMSocketInterface, public GMObject, public GMSerializable
{
public:
    GMSocket();
    GMSocket(StockNodeInterface* stock_node_interface);
    GMQtGraphicSocket *GetStockGraphicsSocket() override;
    QPointF GetSocketPosition() override;
    void SetStockNode(StockNodeInterface* stock_node) override;
    void AddRelatedEdge(StockEdgeInterface* stock_edge_interface) override;
    std::vector<StockEdgeInterface*> GetAllRelatedEdge() override;
    StockNodeInterface* GetStockNode() override;

public:
    void SetPosition(std::pair<double, double> pos);
    void SetIdentifier(int identifier);
    int GetIdentifier();
    int GetPosition();

public:
    std::string serialize() override;
    GMObject* deserialize(std::string str) override;

private:
    StockNodeInterface* m_gmqt_node_interface=nullptr;
    StockEdgeInterface* m_gmqt_edge_interface=nullptr;
    GMQtGraphicSocket* m_gmqt_graphics_socket=nullptr;
    // one to many
    std::vector<StockEdgeInterface*> m_gmqt_edge_interface_vec;
    int m_identifier;
    int m_position;
};

#endif // STOCKSOCKET_H
