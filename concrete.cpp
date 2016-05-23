#include "concrete.h"


Concrete::Concrete(int xPos, int yPos, QObject *parent) : QObject(parent)
{
    setRect(xPos * 16, yPos * 16, 15, 15);
}
