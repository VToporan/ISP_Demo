#include "handlebar.hpp"

#include <QGraphicsScene>

Handlebar::Handlebar(Resizable *parent, AnchorPosition position) : QGraphicsRectItem(QRectF(0, 0, ANCHOR_SIZE, ANCHOR_SIZE), parent) {
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemSendsGeometryChanges);
    setBrush(QBrush(Qt::red));
    setPosition(position);
    this->parent = parent;
}

void Handlebar::setPosition(AnchorPosition newPosition) { currentPosition = newPosition; }

AnchorPosition Handlebar::getPosition() { return currentPosition; }

QVariant Handlebar::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (change == ItemPositionChange && scene()) {
        QPointF newPos = value.toPointF();
        QRectF sceneRect = parent->sceneRect();
        QRectF itemRect = rect();
        qreal rightMargin = sceneRect.right() - parent->x() - itemRect.width() / 2 - 1;
        qreal leftMargin = sceneRect.left() - parent->x() - itemRect.width() / 2 + 1;
        qreal bottomMargin = sceneRect.bottom() - parent->y() - itemRect.height() / 2 - 1;
        qreal topMargin = sceneRect.top() - parent->y() - itemRect.height() / 2 + 1;

        newPos.setX(qMin(rightMargin, qMax(newPos.x(), leftMargin)));
        newPos.setY(qMin(bottomMargin, qMax(newPos.y(), topMargin)));
        return newPos;
    }

    if (change == ItemPositionHasChanged) {
        parent->update(currentPosition);
    }

    return QGraphicsItem::itemChange(change, value);
}
