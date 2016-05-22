#ifndef BASE_H
#define BASE_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>

class Base : public QGraphicsRectItem
{
public:
    Base(int xPos, int yPos, QGraphicsScene *scene);
};

#endif // BASE_H
