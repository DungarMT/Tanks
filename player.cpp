#include <QGraphicsScene>
#include <QList>
#include "player.h"
#include "bullet.h"
#include "brick.h"
#include "concrete.h"

Player::Player(char side) : Tank(side)
{

}

void Player::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Left:
        this->side = 'L';
        if(x() > 0)
            setPos(x()-2, y());
        break;
    case Qt::Key_Right:
        this->side = 'R';
        if(x() + 32 < 800)
            setPos(x()+2, y());
        break;
    case Qt::Key_Up:
        this->side = 'U';
        if(y() > 0)
            setPos(x(), y()-2);
        break;
    case Qt::Key_Down:
        this->side = 'D';
        if(y() + 32 < 600)
            setPos(x(), y()+2);
        break;
    case Qt::Key_Space:
        Bullet *bullet = new Bullet(this->side);
        switch(side){
        case 'U':
            bullet->setPos(x()+13, y());
            bullet->setRect(0, 0, 6, 8);
            break;
        case 'D':
            bullet->setPos(x()+13, y()+24);
            bullet->setRect(0, 0, 6, 8);
            break;
        case 'L':
            bullet->setPos(x(), y()+12);
            bullet->setRect(0, 0, 8, 6);
            break;
        case 'R':
            bullet->setPos(x()+24, y()+13);
            bullet->setRect(0, 0, 8, 6);
            break;
        }

        scene()->addItem(bullet);
    }
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0; i < colliding_items.size(); i++){
        if(typeid(*(colliding_items[i])) == typeid(Brick) ||
           typeid(*(colliding_items[i])) == typeid(Concrete))
        {
            if(side == 'U'){
                setPos(x(), y()+2);
                break;
            }
            else if (side == 'D'){
                setPos(x(), y()-2);
                break;
            }
            else if (side == 'L'){
                setPos(x()+2, y());
                break;
            }
            else if (side == 'R'){
                setPos(x()-2, y());
                break;
            }
        }
    }
}
