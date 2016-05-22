#include "bullet.h"
#include "block.h"
#include <QTimer>
#include <QList>
#include <typeinfo>

Bullet::Bullet(char side, int stars)
{
    this->setZValue(1);
    this->setBrush(* new QBrush(Qt::white));
    this->side = side;
    this->stars = stars;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(5);
}

void Bullet::move()
{
    bool deleted = false;
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0; i < colliding_items.size(); i++){
        if(typeid(*(colliding_items[i])) == typeid(Brick)){
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            deleted = true;
        }
        else if(typeid(*(colliding_items[i])) == typeid(Concrete))
        {
            if(stars==3){
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
            }
            deleted = true;
        }

    }
    if(deleted){
        scene()->removeItem(this);
        delete this;
        return;
    }

    switch(this->side){
    case 'U':
        setPos(x(), y()-1);
        if(pos().y() == 5){
            scene()->removeItem(this);
            delete this;
        }
        break;
    case 'D':
        setPos(x(), y()+1);
        if(pos().y() == 600){
            scene()->removeItem(this);
            delete this;
        }
        break;
    case 'L':
        setPos(x()-1, y());
        if(pos().x() == 0){
            scene()->removeItem(this);
            delete this;
        }
        break;
    case 'R':
        setPos(x()+1, y());
        if(pos().x() == 800){
            scene()->removeItem(this);
            delete this;
        }
        break;
    }
}
