#include <sstream>
#include "gmsocket.h"
#include "json/json.hpp"

GMSocket::GMSocket()
{
    m_gmqt_graphics_socket = new GMQtGraphicSocket(this);
}

GMSocket::GMSocket(GMNode* parent, int pos)
{
    m_gmqt_graphics_socket = new GMQtGraphicSocket(this);
    m_position = pos;
    m_gm_node = parent;
    this->SetPosition(parent->GetAnchor(pos));
    m_gmqt_graphics_socket->setParentItem(parent->GetStockGraphicsNode());

}


GMQtGraphicSocket *GMSocket::GetStockGraphicsSocket()
{
    return m_gmqt_graphics_socket;
}

QPointF GMSocket::GetSocketPosition()
{
    return m_gmqt_graphics_socket->mapToScene(0,0);
}

void GMSocket::SetStockNode(StockNodeInterface *stock_node)
{
    m_gmqt_node_interface = stock_node;
}


void GMSocket::AddRelatedEdge(StockEdgeInterface *stock_edge_interface)
{
    m_gmqt_edge_interface_vec.push_back(stock_edge_interface);
}

std::vector<StockEdgeInterface *> GMSocket::GetAllRelatedEdge()
{
    return m_gmqt_edge_interface_vec;
}

StockNodeInterface *GMSocket::GetStockNode()
{
    return m_gmqt_node_interface;
}


void GMSocket::SetPosition(std::pair<double, double> pos)
{
    m_gmqt_graphics_socket->setPos(QPointF(pos.first, pos.second));
    m_gmqt_graphics_socket->update();
}

void GMSocket::SetIdentifier(int identifier)
{
    m_identifier = identifier;
}

int GMSocket::GetPosition()
{
    return m_position;
}

void GMSocket::SetLocalPosition(int pos)
{
    m_position = pos;
}

void GMSocket::SetParentItem(QGraphicsItem *parent)
{
    m_gmqt_graphics_socket->setParentItem(parent);
}


std::string GMSocket::serialize()
{
    GMQtGraphicSocket* socket = static_cast<GMQtGraphicSocket*>(m_gmqt_graphics_socket);
    nlohmann::json js;
    js = {"identifier", reinterpret_cast<std::uintptr_t>(this)};

    return js.dump();
}

GMObject* GMSocket::deserialize(std::string data)
{
    std::stringstream ss;
    ss<<data;
    nlohmann::json js;
    ss>>js;
    m_identifier = js["identifier"];
    m_position = js["position"];
    return nullptr;
}

