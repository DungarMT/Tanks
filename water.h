#ifndef WATER_H
#define WATER_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>


class Water : public QGraphicsRectItem
{
public:
    Water(int xPos, int yPos, QGraphicsScene *scene, QWidget *parent);
    Water(int xPos, int yPos, QGraphicsScene *scene);

};

#endif // WATER_H
