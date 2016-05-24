#include "base.h"

Base::Base(int xPos, int yPos, QObject *parent): QObject(parent)
{
    setRect(xPos * 16, yPos * 16, 32, 32);
    setPen(Qt::NoPen);
    setBrush(QPixmap(":/img/base.png"));
}

