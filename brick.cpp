#include "brick.h"


Brick::Brick(int xPos, int yPos, QGraphicsScene *scene, QWidget *parent)
{

    Brick *brick_one = new Brick(xPos,yPos,scene);
    Brick *brick_two = new Brick(xPos+16,yPos,scene);
    Brick *brick_three = new Brick(xPos,yPos+16,scene);
    Brick *brick_four = new Brick(xPos+16,yPos+16,scene);
}

Brick::Brick(int xPos, int yPos, QGraphicsScene *scene)
{
    this->setRect(xPos, yPos, 15, 15);
    this->setBrush(* new QBrush(Qt::red));
    scene->addItem(this);
}
