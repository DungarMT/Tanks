#include "player.h"

Player::Player(int xPos, int yPos, QObject *parent) : QObject(parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPen(Qt::NoPen);
    setRect(xPos * 16, yPos * 16, 32, 32);
    setBrush(QPixmap(":/img/player1up.png"));
    this->setZValue(1);
}
