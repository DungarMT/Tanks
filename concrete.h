#ifndef CONCRETE_H
#define CONCRETE_H

#include <QGraphicsRectItem>

class Concrete : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Concrete(int xPos, int yPos, QObject *parent = 0);
};

#endif // CONCRETE_H
