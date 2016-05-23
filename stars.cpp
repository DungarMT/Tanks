#include "stars.h"

Stars::Stars(int xPos, int yPos, QObject *parent) : QObject(parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPen(Qt::NoPen);
    setRect(xPos * 16, yPos * 16, 32, 32);
    setBrush(QPixmap("C:\\Users\\Gnom\\Documents\\GitHub\\Tanks\\star.png"));
    this->setZValue(1);
}
