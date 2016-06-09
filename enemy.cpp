#include "enemy.h"

Enemy::Enemy(int xPos, int yPos, int speed, int health, QObject *parent): QObject(parent)
{
    this->speed=speed;
    this->health=health;
    animation = true;
    this->xPos=xPos;
    this->yPos=yPos;
    posX=xPos*16;
    posY=yPos*16;
    EnemyId=StaticId;
    StaticId++;
    setRect(0,0, 32, 32);
    setPos(xPos * 16, yPos * 16);
    setPen(Qt::NoPen);
    if(speed==2)
        this->setBrush(QPixmap(":/img/tank_lvl_2/tank1down"));
    else
        this->setBrush(QPixmap(":/img/tank_lvl_1/tank1down"));
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
    timerBullet->start(2500);
}

Enemy::~Enemy()
{

    emit delMapCoord(xPos,yPos,true,side);
    spawnExplosion(posX,posY,true);
}

int Enemy::getX()
{
    return posX;
}

int Enemy::getY()
{
    return posY;
}

int Enemy::getHealth()
{
    return health;
}

void Enemy::setX(int x)
{
    posX=x;
}

void Enemy::setY(int y)
{
    posY=y;
}

void Enemy::setHealth(int health)
{
    this->health=health;
}

void Enemy::start()
{
    timer->start(saveTimer);
    timerAnimation->start(saveTimerAnimation);
    timerBullet->start(saveTimerBullet);
}

void Enemy::pause()
{
    saveTimer=timer->remainingTime();
    saveTimerAnimation=timerAnimation->remainingTime();
    saveTimerBullet=timerBullet->remainingTime();
    timerAnimation->stop();
    timerBullet->stop();
    timer->stop();
}

void Enemy::xya(Enemy *buff)
{
    buff->setX(posX);
    buff->setY(posY);
    buff->setHealth(health);
}



void Enemy::spawnBulletEnemy()
{
    timerBullet->start(2500);
    emit spawnBullet(posX,posY,side,-1);
}

void Enemy::move()
{
    timer->start(20);
    switch (side) {
    case 'D':
        if(animation){
            if(speed==2)
                this->setBrush(QPixmap(":/img/tank_lvl_2/tank1down"));
            else
                this->setBrush(QPixmap(":/img/tank_lvl_1/tank1down"));
            animation = false;
        }
        else{
            if(speed==2)
                this->setBrush(QPixmap(":/img/tank_lvl_2/tank2down"));
            else
                this->setBrush(QPixmap(":/img/tank_lvl_1/tank2down"));
            animation = true;
        }
        posY+=2*speed;
        setPos(x(),y()+2*speed);
        count+=1*speed;
        break;
    case 'L':
        if(animation){
            if(speed==2)
                this->setBrush(QPixmap(":/img/tank_lvl_2/tank1left"));
            else
                this->setBrush(QPixmap(":/img/tank_lvl_1/tank1left"));
            animation = false;
        }
        else{
            if(speed==2)
                this->setBrush(QPixmap(":/img/tank_lvl_2/tank2left"));
            else
                this->setBrush(QPixmap(":/img/tank_lvl_1/tank2left"));
            animation = true;
        };
        posX-=2*speed;
        setPos(x()-2*speed, y());
        count+=1*speed;
        break;
    case 'U':
        if(animation){
            if(speed==2)
                this->setBrush(QPixmap(":/img/tank_lvl_2/tank1up"));
            else
                this->setBrush(QPixmap(":/img/tank_lvl_1/tank1up"));
            animation = false;
        }
        else{
            if(speed==2)
                this->setBrush(QPixmap(":/img/tank_lvl_2/tank2up"));
            else
                this->setBrush(QPixmap(":/img/tank_lvl_1/tank2up"));
            animation = true;
        }
        posY-=2*speed;
        setPos(x(),y()-2*speed);
        count+=1*speed;
        break;
    case 'R':
        if(animation){
            if(speed==2)
                this->setBrush(QPixmap(":/img/tank_lvl_2/tank1right"));
            else
                this->setBrush(QPixmap(":/img/tank_lvl_1/tank1right"));
            animation = false;
        }
        else{
            if(speed==2)
                this->setBrush(QPixmap(":/img/tank_lvl_2/tank2right"));
            else
                this->setBrush(QPixmap(":/img/tank_lvl_1/tank2right"));
            animation = true;
        }
        posX+=2*speed;
        setPos(x()+2*speed,y());
        count+=1*speed;
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
    timerAnimation->start(80);
    switch (side) {
    case 'D':
        if(animation){
            if(speed==2)
                this->setBrush(QPixmap(":/img/tank_lvl_2/tank1down"));
            else
                this->setBrush(QPixmap(":/img/tank_lvl_1/tank1down"));
            animation = false;
        }
        else{
            if(speed==2)
                this->setBrush(QPixmap(":/img/tank_lvl_2/tank2down"));
            else
                this->setBrush(QPixmap(":/img/tank_lvl_1/tank2down"));
            animation = true;
        }
        break;
    case 'L':
        if(animation){
            if(speed==2)
                this->setBrush(QPixmap(":/img/tank_lvl_2/tank1left"));
            else
                this->setBrush(QPixmap(":/img/tank_lvl_1/tank1left"));
            animation = false;
        }
        else{
            if(speed==2)
                this->setBrush(QPixmap(":/img/tank_lvl_2/tank2left"));
            else
                this->setBrush(QPixmap(":/img/tank_lvl_1/tank2left"));
            animation = true;
        };
        break;
    case 'U':
        if(animation){
            if(speed==2)
                this->setBrush(QPixmap(":/img/tank_lvl_2/tank1up"));
            else
                this->setBrush(QPixmap(":/img/tank_lvl_1/tank1up"));
            animation = false;
        }
        else{
            if(speed==2)
                this->setBrush(QPixmap(":/img/tank_lvl_2/tank2up"));
            else
                this->setBrush(QPixmap(":/img/tank_lvl_1/tank2up"));
            animation = true;
        }
        break;
    case 'R':
        if(animation){
            if(speed==2)
                this->setBrush(QPixmap(":/img/tank_lvl_2/tank1right"));
            else
                this->setBrush(QPixmap(":/img/tank_lvl_1/tank1right"));
            animation = false;
        }
        else{
            if(speed==2)
                this->setBrush(QPixmap(":/img/tank_lvl_2/tank2right"));
            else
                this->setBrush(QPixmap(":/img/tank_lvl_1/tank2right"));
            animation = true;
        }
        break;
    default:
        break;
    }
}

int Enemy::StaticId = 1;
