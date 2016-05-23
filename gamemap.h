#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>

#include "player.h"

class GameMap : public QObject
{
    Q_OBJECT
public:
    GameMap(QGraphicsScene *workScene, QObject *parent = 0);
    void createPlayer(int xPos, int yPos);
private:
    int map[26][26];
    QGraphicsScene *workScene;
};

#endif // GAMEMAP_H
