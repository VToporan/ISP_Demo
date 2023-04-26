#include "roi.hpp"
#include "resizable/resizable.hpp"

Roi::Roi(const QRectF &rect, QGraphicsItem *parent) : Resizable(rect, parent) {
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemSendsGeometryChanges);

    for (int i = 0; i < TOTAL_ANCHORS; ++i) {
        handles.push_back(new Handlebar(this, (AnchorPosition)i));
    }

    setupHandles();
}

void Roi::setupHandles() {
    initialised = false;

    qreal xOffset = rect().x() - handles.front()->rect().width() / 2;
    qreal yOffset = rect().y() - handles.front()->rect().height() / 2;
    handles[TOP_LEFT]->setPos(xOffset + 1, yOffset + 1);
    handles[TOP_RIGHT]->setPos(xOffset + rect().width() - 1, yOffset + 1);
    handles[BOTTOM_LEFT]->setPos(xOffset + 1, yOffset + rect().height() - 1);
    handles[BOTTOM_RIGHT]->setPos(xOffset + rect().width() - 1, yOffset + rect().height() - 1);

    initialised = true;
}

void Roi::updateNeighbours(AnchorPosition currentAnchor) {
    initialised = false;

    int xOffset = 1;
    int yOffset = 2;

    if (currentAnchor % 2) {
        xOffset = -1;
    }

    if (currentAnchor >= TOTAL_ANCHORS / 2) {
        yOffset = -2;
    }

    handles[currentAnchor + yOffset]->setX(handles[currentAnchor]->x());
    handles[currentAnchor + xOffset]->setY(handles[currentAnchor]->y());

    initialised = true;
}

void Roi::update(AnchorPosition currentAnchor) {
    if (!initialised) {
        return;
    }

    updateNeighbours(currentAnchor);

    qreal xMin = scene()->sceneRect().right();
    qreal yMin = scene()->sceneRect().bottom();
    qreal xMax = scene()->sceneRect().left();
    qreal yMax = scene()->sceneRect().top();

    for (Handlebar *handle : handles) {
        xMin = qMin(xMin, handle->x());
        yMin = qMin(yMin, handle->y());
        xMax = qMax(xMax, handle->x());
        yMax = qMax(yMax, handle->y());
    }

    qreal xOffset = handles.front()->rect().width() / 2;
    qreal yOffset = handles.front()->rect().height() / 2;
    qreal width = qAbs(xMax - xMin);
    qreal heignt = qAbs(yMax - yMin);

    xMin += xOffset;
    yMin += yOffset;

    setRect(xMin, yMin, width, heignt);
}

QVariant Roi::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (change == ItemPositionChange && scene()) {
        QPointF newPos = value.toPointF();
        QRectF sceneRect = scene()->sceneRect();
        QRectF itemRect = rect();
        newPos.setX(qMin(sceneRect.right() - rect().x() - itemRect.width() - 1,
                         qMax(newPos.x(), sceneRect.left() - rect().x())));
        newPos.setY(qMin(sceneRect.bottom() - rect().y() - itemRect.height() - 1,
                         qMax(newPos.y(), sceneRect.top() - rect().y())));
        return newPos;
    }

    return QGraphicsItem::itemChange(change, value);
}