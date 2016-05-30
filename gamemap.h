#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QFile>
#include <QTime>


#include "player.h"
#include "brick.h"
#include "concrete.h"
#include "water.h"
#include "bush.h"
#include "ice.h"
#include "base.h"
#include "enemy.h"

class GameMap : public QObject
{
    Q_OBJECT
public:
    GameMap(QGraphicsScene *workScene, QObject *parent = 0);
    void loadMap();
private:
    int map[26][26];
    QGraphicsScene *workScene;
    void createPlayer(int xPos, int yPos);
    void createBase(int xPos, int yPos);
    void createBlock(int xPos, int yPos, int idBlock);
signals:
    void motion(char side, bool flag);
public slots:
    void changePlayerCoord(int xPos, int yPos);
    void checkCoord(int xPos, int yPos, char side);
    void changeCoord(int xPos, int yPos, char side);
};

#endif // GAMEMAP_H
