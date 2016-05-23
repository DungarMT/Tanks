#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QFile>

#include "player.h"

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

};

#endif // GAMEMAP_H
