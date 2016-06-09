#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QFile>
#include <QTime>
#include <QVector>
#include <QTimer>
#include <typeinfo>
#include <QList>
#include <QPainter>


#include "player.h"
#include "brick.h"
#include "concrete.h"
#include "water.h"
#include "bush.h"
#include "ice.h"
#include "base.h"
#include "enemy.h"
#include "bullet.h"
#include "explosion.h"
#include "stars.h"
#include "shield.h"
#include "helmet.h"
#include "pistol.h"
#include "shovel.h"
#include "granade.h"
#include "health.h"
#include "gameover.h"
#include "healthpanel.h"
#include "blink.h"

class GameMap : public QObject
{
    Q_OBJECT
public:
    GameMap(QGraphicsScene *workScene, QObject *parent = 0);
    void loadMap();
    void end();
    void showInterface();
    void removeEnemyInterfase();
private:
    QVector <QGraphicsRectItem *> enemyList;
    int countEnemy;
    int health;
    QTimer *timerShovel;
    QVector<Concrete*> shovel;
    QVector<int> enemyQueue;
    QTimer *blinkTimer;
    QTimer *stars;
    QTimer *animationTimer;
    int map[26][26];
    QGraphicsScene *workScene;

    void loadEnemys();
    void createPlayer(int xPos, int yPos);
    void createBase(int xPos, int yPos);
    void createBlock(int xPos, int yPos, int idBlock);
signals:
    void pause();
    void gameLoss();
    void xyaSIGNAL(Enemy *buff);
    void changeHealth(int count);
    void CheckShield();
    void moveShideld(char side);
    void motion(char side, bool flag, int id);
public slots:
    void killBase();
    void xyaSLOT(Enemy* buff);
    void spawnEnemy(int xPos, int yPos);
    void addHealth();
    void killEnemy();
    void deleteShovel();
    void createShovel();
    void moveShieldSlot(char side);
    void spawnShield(int xPos, int yPos);
    void delMapCoord(int xPos, int yPos, bool tank, char side);
    void delMapCoord(int xPos, int yPos, bool tank);
    void spawnExplosion(int xPos,int yPos, bool tank);
    void spawnBullet(int xPos,int yPos, char side, int stars);
    void changePlayerCoord(int xPos, int yPos);
    void checkCoord(int xPos, int yPos, char side, int id);
    void changeCoord(int xPos, int yPos, char side, int id);
    void checkPlayerCoord(int xPos, int yPos, int direction, bool &tmp);
    void spawnStars();
    void spawnBlink();
    void CheckShieldSlot();
    void CheckHealth();
};

#endif // GAMEMAP_H
