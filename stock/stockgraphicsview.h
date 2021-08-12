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
#include "stockgraphicscuttingline.h"
#include "StockSocketInterface.h"

class StockGraphicsView : public QGraphicsView
{

    Q_OBJECT

public:
    StockGraphicsView(QWidget *parent=nullptr);
    StockGraphicsView(QGraphicsScene* scene, QWidget* parent=nullptr);
    ~StockGraphicsView();

public:
    void SetStockGraphicScene(StockGraphicsScene* stock_graphics_scene);
    void SetStockGraphicsCuttingLine(StockGraphicsCuttingLine* stock_graphics_cutting_line);

public slots:
    void RemoveSelectedItems();


private:
    QAction* m_remove_action;

protected:
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void contextMenuEvent(QContextMenuEvent* event) override;

private:
    int m_mode=1;
    StockGraphicsScene* m_stock_graphics_scene;  
    StockGraphicsCuttingLine* m_stock_graphics_cutting_line;

    StockEdgeInterface* m_drag_stock_edge_interface;
    StockSocketInterface* m_drag_stock_edge_start;
    StockSocketInterface* m_drag_stock_edge_end;

};

#endif // GRAPHICSVIEW_H
