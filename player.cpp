#include "player.h"

Player::Player(int xPos, int yPos, QObject *parent) : QObject(parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setRect(xPos * 16, yPos * 16, 31, 31);
    setBrush(QBrush(QColor(255, 255, 94)));
    this->setZValue(1);
}
