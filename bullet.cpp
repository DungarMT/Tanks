#include "bullet.h"
#include "block.h"
#include <QTimer>
#include <QList>
#include <typeinfo>

Bullet::Bullet()
{
    setRect(13, 0, 6, 8);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(5);
}

void Bullet::move()
{
    bool deleted = false;
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0; i < colliding_items.size(); i++){
        if(typeid(*(colliding_items[i])) == typeid(Block)){
            scene()->removeItem(colliding_items[i]);


            delete colliding_items[i];
            deleted = true;
        }
    }
    if(deleted){
        scene()->removeItem(this);
        delete this;
        return;
    }

    setPos(x(), y()-1);
    if(pos().y() == 5){
        scene()->removeItem(this);
        delete this;
    }
}
