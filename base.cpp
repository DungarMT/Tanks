#include "base.h"

Base::Base(int xPos, int yPos, QGraphicsScene *scene)
{
    this->setRect(xPos,yPos,31,31);
    scene->addItem(this);
}
