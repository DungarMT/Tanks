#include "base.h"

Base::Base(int xPos, int yPos, QObject *parent): QObject(parent)
{
    setRect(xPos * 16, yPos * 16, 31, 31);
    setBrush(QBrush(QColor(228, 47, 255)));
}

