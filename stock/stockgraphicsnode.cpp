#include "stockgraphicsnode.h"
#include <QPainterPath>
#include "stocknode.h"

StockGraphicsNode::StockGraphicsNode(): QGraphicsItem()
{
    InitUI();
}

StockGraphicsNode::StockGraphicsNode(std::string title)
{
    InitUI();
    m_title = title;
}

StockGraphicsNode::StockGraphicsNode(StockNodeInterface *stock_node_interface, std::string title)
{
    m_stock_node_interface = stock_node_interface;
    m_title = title;
    InitUI();
}

void StockGraphicsNode::InitUI()
{
    this->setFlag(QGraphicsItem::ItemIsSelectable);
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFlag(QGraphicsItem::ItemIsMovable);
}

QRectF StockGraphicsNode::boundingRect() const
{
    return QRectF(0,0,90,120);
}

void StockGraphicsNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

void StockGraphicsNode::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    StockNode* stock_node = static_cast<StockNode*>(m_stock_node_interface);
    std::vector<StockNodeInterface*> nodes_vec = stock_node->GetStockScene()->GetStockNodesVector();
    for(auto v:nodes_vec){
         //m_stock_node_interface->UpdateConnectedEdge();
        StockNode* stock_node = static_cast<StockNode*>(v);
        if(stock_node->GetStockGraphicsNode()->isSelected())
        {
             v->UpdateConnectedEdge();
        }
    }
    QGraphicsItem::mouseMoveEvent(event);
}
