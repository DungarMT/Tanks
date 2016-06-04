#include "enemy.h"

Enemy::Enemy(int xPos, int yPos, QObject *parent): QObject(parent)
{
    animation = true;
    this->xPos=xPos;
    this->yPos=yPos;
    EnemyId=StaticId;
    StaticId++;
    setRect(xPos * 16, yPos * 16, 32, 32);
    setPen(Qt::NoPen);
    setBrush(QPixmap(":/img/tank_lvl_1/tank1down"));
    side='D';
    count=0;
    timer = new QTimer(this);
    timerAnimation = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(timerAnimation,SIGNAL(timeout()),this,SLOT(TankAnimation()));
    timerAnimation->start(80);
    timer->start(20);
    timerBullet = new QTimer(this);
    connect(timerBullet,SIGNAL(timeout()),this,SLOT(spawnBulletEnemy()));
    timerBullet->start(500);
}

Enemy::~Enemy()
{
    emit delMapCoord(xPos,yPos,true,side);
}

void Enemy::spawnBulletEnemy()
{
    emit spawnBullet(xPos,yPos,side);
}



void Enemy::move()
{

    switch (side) {
    case 'D':
        if(animation){
            this->setBrush(QPixmap(":/img/tank_lvl_1/tank1down"));
            animation = false;
        }
        else{
            this->setBrush(QPixmap(":/img/tank_lvl_1/tank2down"));
            animation = true;
        }
        setPos(x(),y()+2);
        count++;
        break;
    case 'L':
        if(animation){
            this->setBrush(QPixmap(":/img/tank_lvl_1/tank1left"));
            animation = false;
        }
        else{
            this->setBrush(QPixmap(":/img/tank_lvl_1/tank2left"));
            animation = true;
        };
        setPos(x()-2, y());
        count++;
        break;
    case 'U':
        if(animation){
            this->setBrush(QPixmap(":/img/tank_lvl_1/tank1up"));
            animation = false;
        }
        else{
            this->setBrush(QPixmap(":/img/tank_lvl_1/tank2up"));
            animation = true;
        }
        setPos(x(),y()-2);
        count++;
        break;
    case 'R':
        if(animation){
            this->setBrush(QPixmap(":/img/tank_lvl_1/tank1right"));
            animation = false;
        }
        else{
            this->setBrush(QPixmap(":/img/tank_lvl_1/tank2right"));
            animation = true;
        }
        setPos(x()+2,y());
        count++;
        break;
    default:
        break;
    }
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
            break;
        }
        emit checkCoord(xPos,yPos,side,this->EnemyId);
    }
}

void Enemy::motion(char side, bool flag, int id)
{
    if(id==EnemyId){
        if(flag){
            this->side=side;
            emit changeCoord(xPos,yPos,side,id);
        }
        else{
            emit checkCoord(xPos,yPos,side,id);
        }
    }
}

void Enemy::TankAnimation(){
    switch (side) {
    case 'D':
        if(animation){
            this->setBrush(QPixmap(":/img/tank_lvl_1/tank1down"));
            animation = false;
        }
        else{
            this->setBrush(QPixmap(":/img/tank_lvl_1/tank2down"));
            animation = true;
        }
        break;
    case 'L':
        if(animation){
            this->setBrush(QPixmap(":/img/tank_lvl_1/tank1left"));
            animation = false;
        }
        else{
            this->setBrush(QPixmap(":/img/tank_lvl_1/tank2left"));
            animation = true;
        };
        break;
    case 'U':
        if(animation){
            this->setBrush(QPixmap(":/img/tank_lvl_1/tank1up"));
            animation = false;
        }
        else{
            this->setBrush(QPixmap(":/img/tank_lvl_1/tank2up"));
            animation = true;
        }
        break;
    case 'R':
        if(animation){
            this->setBrush(QPixmap(":/img/tank_lvl_1/tank1right"));
            animation = false;
        }
        else{
            this->setBrush(QPixmap(":/img/tank_lvl_1/tank2right"));
            animation = true;
        }
        break;
    default:
        break;
    }
}

int Enemy::StaticId = 1;
