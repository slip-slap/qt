#ifndef STOCKNODE_H
#define STOCKNODE_H


#include "gmsocketinterface.h"
#include "stocknodeinterface.h"
#include "gmqtgraphicsnode.h"
#include "gmscene.h"
#include <QGraphicsScene>
#include <string>

#include "gmobject.h"
#include "gmserializable.h"

enum POSITION {NORTH_ANCHOR, SOUTH_ANCHOR};

class GMNode: public StockNodeInterface, public GMSerializable, public GMObject
{
public:
    GMNode(GMScene* scene);

    GMNode(GMScene* stock_scene, std::string title,
              GMSocketInterface* socket1);
    GMNode(GMScene* stock_scene, std::string title,
              GMSocketInterface* socket1,
              GMSocketInterface* socket2);

    GMQtGraphicsNode* GetStockGraphicsNode();
    GMScene* GetGMScene();
    void RemoveNode();
    GMSocketInterface* GetGMSocket(int pos);

    GMSocketInterface *GetStockSocketInterface();
    void SetStockNodePosition(QPointF pos);

    void UpdateConnectedEdge() override;
    QPointF GetStockNodePosition() override;

public:
    std::pair<double, double> GetNorthAnchor();
    std::pair<double, double> GetSouthAnchor();
    std::pair<double, double> GetWestAnchor();
    std::pair<double, double> GetEastAnchor();


public:
    std::string serialize() override;
    GMObject deserialize(std::string str) override;
    friend std::ostream& operator<<(std::ostream& out, const GMNode& obj);
private:
    GMQtGraphicsNode* m_gmqt_graphics_node;
    GMSocketInterface* m_gmqt_socket_interface1=nullptr;
    GMSocketInterface* m_gmqt_socket_interface2=nullptr;
    GMScene* m_gm_scene;
};

#endif // STOCKNODE_H
