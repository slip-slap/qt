#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QContextMenuEvent>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QEvent>
#include <QFocusEvent>
#include <QInputMethodEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPaintEvent>
#include "stockgraphicsscene.h"

class StockGraphicsView : public QGraphicsView
{

public:
    StockGraphicsView(QWidget *parent=nullptr);
    StockGraphicsView(QGraphicsScene* scene, QWidget* parent=nullptr);
    ~StockGraphicsView();

public:
    void SetStockGraphicScene(StockGraphicsScene* stock_graphics_scene);

protected:
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    StockGraphicsScene* m_stock_graphics_scene;
    int m_mode=1;
    StockEdgeInterface* m_drag_stock_edge_interface;

};

#endif // GRAPHICSVIEW_H
