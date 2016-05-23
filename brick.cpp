#include "brick.h"

Brick::Brick(int xPos, int yPos, QObject *parent): QObject(parent)
{
    setRect(xPos * 16, yPos * 16, 15, 15);
    setBrush(QBrush(QColor(192, 41, 3)));
}
