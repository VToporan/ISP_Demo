#include "roi.hpp"

#include <QGraphicsScene>

Roi::Roi(const QRectF &rect, QGraphicsItem *parent) : QGraphicsRectItem(rect, parent) {
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemSendsGeometryChanges);
}

#include <iostream>
QVariant Roi::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (change == ItemPositionChange && scene()) {
        // value is the new position.
        QPointF newPos = value.toPointF();
        QRectF sceneRect = scene()->sceneRect();
        QRectF itemRect = this->rect();
        newPos.setX(qMin(sceneRect.right() - itemRect.width() - 1, qMax(newPos.x(), sceneRect.left())));
        newPos.setY(qMin(sceneRect.bottom() - itemRect.height() - 1, qMax(newPos.y(), sceneRect.top())));
        return newPos;
    }
    return QGraphicsItem::itemChange(change, value);
}
