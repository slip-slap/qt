#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H


#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
#include <QGraphicsSceneMouseEvent>
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
#include <vector>
#include "StockSocketInterface.h"
#include "stocknode.h"
#include "stockscene.h"


class StockGraphicsScene: public QGraphicsScene
{
public:
    StockGraphicsScene();
    StockGraphicsScene(StockScene* stock_scene);

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

private:
    StockScene* m_stock_scene;
};

#endif // GRAPHICSSCENE_H
