#include "bush.h"

Bush::Bush(int xPos, int yPos, QObject *parent): QObject(parent)
{
    setRect(xPos * 16, yPos * 16, 15, 15);
    setBrush(QBrush(QColor(31, 255, 23)));
    this->setZValue(2);
}
