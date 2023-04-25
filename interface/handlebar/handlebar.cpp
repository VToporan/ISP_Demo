#include "handlebar.hpp"

#include <QGraphicsScene>

Handlebar::Handlebar(Resizable *parent) : QGraphicsRectItem(QRectF(0, 0, 10, 10), parent) {
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemSendsGeometryChanges);
    setBrush(QBrush(Qt::red));
    this->parent = parent;
}

#include <iostream>
QVariant Handlebar::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (change == ItemPositionChange && scene()) {
        QPointF newPos = value.toPointF();
        QRectF sceneRect = parent->sceneRect();
        QRectF itemRect = rect();
        newPos.setX(qMin(sceneRect.right() - parent->x() - itemRect.width() / 2 - 1,
                         qMax(newPos.x(), sceneRect.left() - parent->x() - itemRect.width() / 2 + 1)));
        newPos.setY(qMin(sceneRect.bottom() - itemRect.height() / 2 - 1,
                         qMax(newPos.y(), sceneRect.top() - itemRect.height() / 2 + 1)));
        return newPos;
    }

    if (change == ItemPositionHasChanged) {
        parent->update();
    }

    return QGraphicsItem::itemChange(change, value);
}
