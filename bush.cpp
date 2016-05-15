#include "bush.h"

Bush::Bush(int xPos, int yPos, QGraphicsScene *scene, QWidget *parent)
{
    Bush *Bush_one = new Bush(xPos,yPos,scene);
    Bush *Bush_two = new Bush(xPos+16,yPos,scene);
    Bush *Bush_three = new Bush(xPos,yPos+16,scene);
    Bush *Bush_four = new Bush(xPos+16,yPos+16,scene);
}

Bush::Bush(int xPos, int yPos, QGraphicsScene *scene)
{
    this->setRect(xPos, yPos, 16, 16);
    this->setZValue(2);
    this->setBrush(* new QBrush(Qt::green));
    scene->addItem(this);
}
