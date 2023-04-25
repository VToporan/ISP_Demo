#include "roi.hpp"

#include <iostream>
Roi::Roi(const QRectF &rect, QGraphicsItem *parent) : Resizable(rect, parent) {
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemSendsGeometryChanges);
    setupHandles();
}

void Roi::setupHandles() {
    for (int i = 0; i < TOTAL_ANCHORS; ++i) {
        handles.push_back(new Handlebar(this));
    }
}

void Roi::update() {
    std::cout <<"update\n";
}

QVariant Roi::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (change == ItemPositionChange && scene()) {
        QPointF newPos = value.toPointF();
        QRectF sceneRect = scene()->sceneRect();
        QRectF itemRect = rect();
        newPos.setX(qMin(sceneRect.right() - itemRect.width() - 1, qMax(newPos.x(), sceneRect.left())));
        newPos.setY(qMin(sceneRect.bottom() - itemRect.height() - 1, qMax(newPos.y(), sceneRect.top())));
        return newPos;
    }

    return QGraphicsItem::itemChange(change, value);
}
