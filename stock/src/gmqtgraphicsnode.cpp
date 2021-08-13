#include "gmqtgraphicsnode.h"
#include <QPainterPath>
#include "gmnode.h"

GMQtGraphicsNode::GMQtGraphicsNode(): QGraphicsItem()
{
    InitUI();
}

GMQtGraphicsNode::GMQtGraphicsNode(std::string title)
{
    InitUI();
    m_title = title;
}

GMQtGraphicsNode::GMQtGraphicsNode(StockNodeInterface *stock_node_interface, std::string title)
{
    m_stock_node_interface = stock_node_interface;
    m_title = title;
    InitUI();
}

void GMQtGraphicsNode::InitUI()
{
    this->setFlag(QGraphicsItem::ItemIsSelectable);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFlag(QGraphicsItem::ItemIsMovable);
}

QRectF GMQtGraphicsNode::boundingRect() const
{
    return QRectF(0,0,90,120);
}

void GMQtGraphicsNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


    painter->setBrush(Qt::NoBrush);
    QPainterPath* title = new QPainterPath();

    title->setFillRule(Qt::WindingFill);
    title->addRoundedRect(0,0,90,20,5,5);
    title->addText(0,0,QFont("Times",20),"Tencent");
    title->addText(80,0,QFont("Times",20),m_title.c_str());
    painter->drawPath(title->simplified());

    painter->setBrush(Qt::NoBrush);
    // outline
    if(this->isSelected()){
        painter->setPen(QColor(Qt::yellow));
    }
    painter->drawRoundedRect(0,0,90,120,10,10);
}

void GMQtGraphicsNode::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    GMNode* stock_node = static_cast<GMNode*>(m_stock_node_interface);
    std::vector<StockNodeInterface*> nodes_vec = stock_node->GetGMScene()->GetStockNodesVector();
    for(auto v:nodes_vec){
         //m_stock_node_interface->UpdateConnectedEdge();
        GMNode* stock_node = static_cast<GMNode*>(v);
        if(stock_node->GetStockGraphicsNode()->isSelected())
        {
             v->UpdateConnectedEdge();
        }
    }
    QGraphicsItem::mouseMoveEvent(event);
}
