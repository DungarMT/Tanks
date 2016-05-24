#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include "gamemap.h"

class Player : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Player(int xPos, int yPos, GameMap *map, QObject *parent = 0);

private:
    GameMap *map;

signals:

public slots:
};

#endif // PLAYER_H
