#ifndef ROI_H
#define ROI_H

#include "handlebar/handlebar.hpp"
#include "resizable/resizable.hpp"

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <vector>

class Roi : public Resizable {
    public:
        Roi(const QRectF &rect, QGraphicsItem *parent = 0);
        void update(AnchorPosition currentAnchor);
        void setSelected(bool isSelected);

    protected:
        virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    private:
        void setupHandles();
        void handlebarUpdateNeighbours(AnchorPosition currentAnchor);
        std::vector<Handlebar *> handles;
};

#endif
