#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QTimer>


class Enemy: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Enemy(int xPos, int yPos, QObject *parent = 0);
    ~Enemy();
private:
    bool animation;
    int xPos, yPos, posX, posY;
    static int StaticId;
    int EnemyId;
    char side;
    int count;
    QTimer *timer;
    QTimer *timerAnimation;
    QTimer *timerBullet;
signals:
    void spawnExplosion(int,int,bool);
    void delMapCoord(int,int,bool,char);
    void spawnBullet(int,int,char, int);
    void checkCoord(int,int,char, int);
    void changeCoord(int,int,char, int);
private slots:
    void spawnBulletEnemy();
    void TankAnimation();
    void move();
    void motion(char side ,bool flag, int id);
};

#endif // ENEMY_H
