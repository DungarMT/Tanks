#ifndef BRICK_H
#define BRICK_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>


class Brick : public QGraphicsRectItem
{
public:
    Brick(int xPos, int yPos, QGraphicsScene *scene, QWidget *parent);
    Brick(int xPos, int yPos, QGraphicsScene *scene);

};

#endif // BRICK_H
