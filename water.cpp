#include "water.h"


Water::Water(int xPos, int yPos, QGraphicsScene *scene, QWidget *parent)
{

    Water *Water_one = new Water(xPos,yPos,scene);
    Water *Water_two = new Water(xPos+16,yPos,scene);
    Water *Water_three = new Water(xPos,yPos+16,scene);
    Water *Water_four = new Water(xPos+16,yPos+16,scene);
}

Water::Water(int xPos, int yPos, QGraphicsScene *scene)
{
    this->setRect(xPos, yPos, 15, 15);
    this->setBrush(* new QBrush(Qt::blue));
    scene->addItem(this);
}
