#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QFile>
#include <QTime>

#include <QTimer>


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

class GameMap : public QObject
{
    Q_OBJECT
public:
    GameMap(QGraphicsScene *workScene, QObject *parent = 0);
    void loadMap();
private:
    QTimer *animationTimer;
    int map[26][26];
    QGraphicsScene *workScene;
    void createPlayer(int xPos, int yPos);
    void createBase(int xPos, int yPos);
    void createBlock(int xPos, int yPos, int idBlock);
    void spawnEnemy(int xPos, int yPos);
signals:
    void motion(char side, bool flag, int id);
public slots:
    void delMapCoord(int xPos, int yPos, bool tank, char side);
    void delMapCoord(int xPos, int yPos, bool tank);
    void spawnExplosion(int xPos,int yPos, bool tank);
    void spawnBullet(int xPos,int yPos, char side);
    void changePlayerCoord(int xPos, int yPos);
    void checkCoord(int xPos, int yPos, char side, int id);
    void changeCoord(int xPos, int yPos, char side, int id);
    void checkPlayerCoord(int xPos, int yPos, int direction, bool &tmp);
};

#endif // GAMEMAP_H
