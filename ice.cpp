#include "ice.h"

Ice::Ice(int xPos, int yPos, QGraphicsScene *scene, QWidget *parent)
{
    Ice *Ice_one = new Ice(xPos,yPos,scene);
    Ice *Ice_two = new Ice(xPos+16,yPos,scene);
    Ice *Ice_three = new Ice(xPos,yPos+16,scene);
    Ice *Ice_four = new Ice(xPos+16,yPos+16,scene);
}

Ice::Ice(int xPos, int yPos, QGraphicsScene *scene)
{
    this->setRect(xPos, yPos, 15, 15);
    scene->addItem(this);
}
