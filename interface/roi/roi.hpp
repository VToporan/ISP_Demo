#ifndef ROI_H
#define ROI_H

#include <QGraphicsRectItem>

class Roi : public QGraphicsRectItem {
    public:
        Roi(const QRectF &rect, QGraphicsItem *parent = 0);

    protected:
        virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);
};

#endif
