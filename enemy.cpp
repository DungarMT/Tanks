#include "enemy.h"

Enemy::Enemy(int xPos, int yPos, QObject *parent): QObject(parent)
{
    this->xPos=xPos;
    this->yPos=yPos;
    EnemyId=StaticId;
    StaticId++;
    setRect(xPos * 16, yPos * 16, 32, 32);
    setPen(Qt::NoPen);
    setBrush(QPixmap(":/img/brick.png"));
    side='R';
    count=0;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(20);
}

void Enemy::move()
{
    switch (side) {
    case 'D':
        setPos(x(),y()+2);
        count++;
        break;
    case 'L':
        setPos(x()-2, y());
        count++;
        break;
    case 'U':
        setPos(x(),y()-2);
        count++;
        break;
    case 'R':
        setPos(x()+2,y());
        count++;
        break;
    default:
        count++;
        break;
    }
    int a=x();
    if(count>=8){
        count=0;
        //timer->stop();
        switch (side) {
        case 'D':
            yPos++;
            break;
        case 'L':
            xPos--;
            break;
        case 'U':
            yPos--;
            break;
        case 'R':
            xPos++;
            break;
        default:
            count++;
            break;
        }
        emit checkCoord(xPos,yPos,side);
    }
}

void Enemy::motion(char side, bool flag)
{
    if(flag){
        this->side=side;
        emit changeCoord(xPos,yPos,side);
    }
    else{
        emit checkCoord(xPos,yPos,side);
    }
}
int Enemy::StaticId = 1;
