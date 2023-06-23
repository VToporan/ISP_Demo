#include "resizable.hpp"

Resizable::Resizable(const QRectF &rect, QGraphicsItem *parent) : QGraphicsRectItem(rect, parent) {
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemSendsGeometryChanges);
}

QRectF Resizable::sceneRect() {
    return scene()->sceneRect();
}
