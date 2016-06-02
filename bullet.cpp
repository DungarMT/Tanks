#include "bullet.h"

Bullet::Bullet(int xPos, int yPos, char side, QObject *parent): QObject(parent)
{
    BulletId=StaticId;
    StaticId++;
    this->side=side;
    setPen(Qt::NoPen);
    switch (side) {
    case 'D':
        setRect((xPos * 16)+12, yPos * 16+48, 8, 8);
        setBrush(QPixmap(":/img/bulletDown.png"));
        break;
    case 'R':
        setRect(xPos * 16+48, (yPos * 16)+12, 8, 8);
        setBrush(QPixmap(":/img/bulletRight.png"));
        break;
    case 'U':
        setRect((xPos * 16)+12, yPos * 16-24, 8, 8);
        setBrush(QPixmap(":/img/bulletUp.png"));
        break;
    case 'L':
        setRect(xPos * 16-24, (yPos * 16)+12, 8, 8);
        setBrush(QPixmap(":/img/bulletLeft.png"));
        break;
    default:
        break;
    }
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}
int Bullet::StaticId = 1;

void Bullet::move()
{
    bool deleted = false;
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for(int i = 0; i < colliding_items.size(); i++){
            if(typeid(*(colliding_items[i])) == typeid(Brick)){
                delete colliding_items[i];
                deleted = true;
            }
            else if(typeid(*(colliding_items[i])) == typeid(Concrete))
            {
                deleted = true;
            }
            else if(typeid(*(colliding_items[i])) == typeid(Enemy)){
                delete colliding_items[i];
                deleted = true;
            }
            else if(typeid(*(colliding_items[i])) == typeid(Base))
            {
                delete colliding_items[i];
                deleted = true;
            }
            else if(typeid(*(colliding_items[i])) == typeid(Player))
            {
                delete colliding_items[i];
                deleted = true;
            }
        }
        if(deleted){
            delete this;
            return;
        }

    switch (side) {
    case 'D':
        setPos(x(),y()+2);
        break;
    case 'L':
        setPos(x()-2, y());
        break;
    case 'U':
        setPos(x(),y()-2);
        break;
    case 'R':
        setPos(x()+2,y());
        break;
    default:
        break;
    }
}
