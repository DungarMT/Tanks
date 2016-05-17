#include "concrete.h"

Concrete::Concrete(int xPos, int yPos, QGraphicsScene *scene, QWidget *parent)
{
    Concrete *Concrete_one = new Concrete(xPos,yPos,scene);
    Concrete *Concrete_two = new Concrete(xPos+17,yPos,scene);
    Concrete *Concrete_three = new Concrete(xPos,yPos+17,scene);
    Concrete *Concrete_four = new Concrete(xPos+17,yPos+17,scene);
}

Concrete::Concrete(int xPos, int yPos, QGraphicsScene *scene)
{
    this->setRect(xPos, yPos, 15, 15);
    this->setBrush(* new QBrush(Qt::black));
    scene->addItem(this);
}
