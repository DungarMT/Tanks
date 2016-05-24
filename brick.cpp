#include "brick.h"

Brick::Brick(int xPos, int yPos, QObject *parent): QObject(parent)
{
    setRect(xPos * 16, yPos * 16, 16, 16);
    setPen(Qt::NoPen);
    setBrush(QPixmap(":/img/brick.png"));

}
