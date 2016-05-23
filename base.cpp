#include "base.h"

Base::Base(int xPos, int yPos, QObject *parent): QObject(parent)
{
    setRect(xPos * 16, yPos * 16, 15, 15);
}

