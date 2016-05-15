#include "upgrades.h"



Upgrades::Upgrades(int xPos, int yPos, QGraphicsScene *scene)
{
    this->setRect(xPos,yPos,32,32);
    scene->addItem(this);
}
