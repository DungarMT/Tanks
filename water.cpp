#include "water.h"

Water::Water(int xPos, int yPos, QObject *parent): QObject(parent)
{
    setRect(xPos * 16, yPos * 16, 16, 16);
    setPen(Qt::NoPen);
    setBrush(QPixmap("C:\\Users\\Gnom\\Documents\\GitHub\\Tanks\\water1.png"));
    this->setZValue(0);
}

