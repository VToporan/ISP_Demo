#ifndef RESIZABLE_H
#define RESIZABLE_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>

enum AnchorPosition{
    TOP_LEFT,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_RIGHT,
    TOTAL_ANCHORS,
};

class Resizable : public QGraphicsRectItem {
    public:
        Resizable(const QRectF &rect, QGraphicsItem *parent = 0);
        virtual ~Resizable() {};
        virtual void update() = 0;
        virtual QRectF sceneRect();
};

#endif
