#include <QGraphicsScene>
#include "player.h"
#include "bullet.h"

void Player::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Left:
        if(x() > 5)
            setPos(x()-5, y());
        break;
    case Qt::Key_Right:
        if(x() < 495)
            setPos(x()+5, y());
        break;
    case Qt::Key_Up:
        if(y() > 0)
            setPos(x(), y()-5);
        break;
    case Qt::Key_Down:
        if(y() < 495)
            setPos(x(), y()+5);
        break;
    case Qt::Key_Space:
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }
}
