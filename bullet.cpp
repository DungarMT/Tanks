#include "bullet.h"
#include <QTimer>

Bullet::Bullet()
{
    setRect(0, 0, 10, 10);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(5);
}

void Bullet::move()
{
    setPos(x(), y()-1);
    if(pos().y() == 5){
        scene()->removeItem(this);
        delete this;
    }
}
