#include "water.h"

Water::Water(int xPos, int yPos, QObject *parent): QObject(parent)
{
    setRect(xPos * 16, yPos * 16, 15, 15);
    setBrush(QBrush(QColor(23, 38, 255)));
    this->setZValue(0);
}

