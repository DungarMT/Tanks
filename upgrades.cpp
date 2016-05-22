#include "upgrades.h"



Upgrades::Upgrades(int xPos, int yPos, QGraphicsScene *scene)
{
    this->setRect(xPos,yPos,31,31);
    this->setZValue(3);
    this->setBrush(* new QBrush(Qt::white));
    scene->addItem(this);
}
