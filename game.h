#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "block.h"

class Game : public QObject
{
    Q_OBJECT
public:
    Game();
    //void setBlock(int xPos, int yPos, QGraphicsScene *game_screen);
};

#endif // GAME_H
