#ifndef HANDLEAR_H
#define HANDLEAR_H

#include "resizable/resizable.hpp"

#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Handlebar : public QGraphicsRectItem {
    public:
        Handlebar(Resizable *parent, AnchorPosition position);
        void setPosition(AnchorPosition newPosition);
        AnchorPosition getPosition();

    protected:
        virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    private:
        Resizable *parent;
        AnchorPosition currentPosition;
};

#endif
