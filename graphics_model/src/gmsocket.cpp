#include "gmsocket.h"
#include "json/json.hpp"

GMSocket::GMSocket()
{
    m_stock_graphics_socket = new GMQtGraphicSocket(this);
}

GMSocket::GMSocket(StockNodeInterface *stock_node_interface)
{
    m_stock_graphics_socket = new GMQtGraphicSocket(this);
    m_stock_node_interface = stock_node_interface;
    m_stock_graphics_socket->setPos(m_stock_node_interface->GetStockNodePosition());
}

GMQtGraphicSocket *GMSocket::GetStockGraphicsSocket()
{
    return m_stock_graphics_socket;
}

QPointF GMSocket::GetSocketPosition()
{
    return m_stock_graphics_socket->mapToScene(0,0);
}

void GMSocket::SetStockNode(StockNodeInterface *stock_node)
{
    m_stock_node_interface = stock_node;
}


void GMSocket::AddRelatedEdge(StockEdgeInterface *stock_edge_interface)
{
    m_stock_edge_interface_vec.push_back(stock_edge_interface);
}

std::vector<StockEdgeInterface *> GMSocket::GetAllRelatedEdge()
{
    return m_stock_edge_interface_vec;
}

StockNodeInterface *GMSocket::GetStockNode()
{
    return m_stock_node_interface;
}

std::string GMSocket::serialize()
{
    double long id = reinterpret_cast<std::uintptr_t>(this);
    nlohmann::json js;
    js = {
        "identifierdd", id
    };
    return js.dump();
}

GMObject GMSocket::deserialize(std::string str)
{
    return GMObject();
}

