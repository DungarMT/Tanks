#include "bullet.h"

Bullet::Bullet(int xPos, int yPos, char side, QObject *parent): QObject(parent)
{
    count = 0;
    this->xPos=xPos*16;
    this->yPos=yPos*16;
    BulletId=StaticId;
    StaticId++;
    this->side=side;
    setPen(Qt::NoPen);
    setRect(xPos * 16, yPos * 16, 8, 8);
    switch (side) {
    case 'D':
        setPos(x()+12,y()+48);
        this->setBrush(QPixmap(":/img/bulletDown.png"));
        break;
    case 'R':
        setPos(x()+48,y()+12);
        this->setBrush(QPixmap(":/img/bulletRight.png"));
        break;
    case 'U':
        setPos(x()+12,y()-24);
        setBrush(QPixmap(":/img/bulletUp.png"));
        break;
    case 'L':
        setPos(x()-24,y()+12);
        setBrush(QPixmap(":/img/bulletLeft.png"));
        break;
    default:
        break;
    }
    emit move();
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
                switch (side) {
                case 'D':
                    emit spawnExplosion(xPos,yPos+46,false);
                    break;
                case 'L':
                    emit spawnExplosion(xPos-46,yPos,false);
                    break;
                case 'U':
                    emit spawnExplosion(xPos,yPos-46,false);
                    break;
                case 'R':
                    emit spawnExplosion(xPos+46,yPos,false);
                    break;
                default:
                    break;
                }
                //emit spawnExplosion(xPos,yPos,false);
                delete colliding_items[i];
                deleted = true;

            }
            else if(typeid(*(colliding_items[i])) == typeid(Concrete))
            {
                switch (side) {
                case 'D':
                    emit spawnExplosion(xPos,yPos+48,false);
                    break;
                case 'L':
                    emit spawnExplosion(xPos-48,yPos,false);
                    break;
                case 'U':
                    emit spawnExplosion(xPos,yPos-48,false);
                    break;
                case 'R':
                    emit spawnExplosion(xPos+48,yPos,false);
                    break;
                default:
                    break;
                }
                //emit spawnExplosion(xPos,yPos,false);
                deleted = true;

            }
            else if(typeid(*(colliding_items[i])) == typeid(Enemy))
            {

                switch (side) {
                case 'D':
                    emit spawnExplosion(xPos,yPos+48,true);;
                    break;
                case 'L':
                    emit spawnExplosion(xPos-48,yPos,true);
                    break;
                case 'U':
                    emit spawnExplosion(xPos,yPos-48,true);
                    break;
                case 'R':
                    emit spawnExplosion(xPos+48,yPos,true);
                    break;
                default:
                    break;
                }
                delete colliding_items[i];
                deleted = true;

            }
            else if(typeid(*(colliding_items[i])) == typeid(Base))
            {
                /*
                switch (side) {
                case 'D':
                    emit spawnExplosion(xPos,yPos+48,true);;
                    break;
                case 'L':
                    emit spawnExplosion(xPos-48,yPos,true);
                    break;
                case 'U':
                    emit spawnExplosion(xPos,yPos-48,true);
                    break;
                case 'R':
                    emit spawnExplosion(xPos+48,yPos,true);
                    break;
                default:
                    break;
                }
                delete colliding_items[i];
                deleted = true;
                */
            }
            else if(typeid(*(colliding_items[i])) == typeid(Player))
            {
                /*
                switch (side) {
                case 'D':
                    emit delMapCoord(xPos/16,yPos/16+3,true);
                    emit spawnExplosion(xPos,yPos+48,true);;
                    break;
                case 'L':
                    emit delMapCoord(xPos/16-3,yPos/16,true);
                    emit spawnExplosion(xPos-48,yPos,true);
                    break;
                case 'U':
                    emit delMapCoord(xPos/16,yPos/16-3,true);
                    emit spawnExplosion(xPos,yPos-48,true);
                    break;
                case 'R':
                    emit delMapCoord(xPos/16+3,yPos/16,true);
                    emit spawnExplosion(xPos+48,yPos,true);
                    break;
                default:
                    break;
                }
                delete colliding_items[i];
                deleted = true;
                emit delMapCoord(xPos/16,yPos/16,true);
                */
            }
        }
        if(deleted){
            delete this;
            return;
        }

    switch (side) {
    case 'D':
        yPos+=2;
        //count++;
        setPos(x(),y()+2);
        break;
    case 'L':
        xPos-=2;
        //count++;
        setPos(x()-2, y());
        break;
    case 'U':
        yPos-=2;
        //count++;
        setPos(x(),y()-2);
        break;
    case 'R':
        xPos+=2;
        //count++;
        setPos(x()+2,y());
        break;
    default:
        break;
    }



}
