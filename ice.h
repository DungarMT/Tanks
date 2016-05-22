#ifndef ICE_H
#define ICE_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>

class Ice: public QGraphicsRectItem
{
public:
    Ice(int xPos, int yPos, QGraphicsScene *scene, QWidget *parent);
    Ice(int xPos, int yPos, QGraphicsScene *scene);
};

#endif // ICE_H
