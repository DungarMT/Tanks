#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "block.h"
#include <QVector>
#include <upgrades.h>
#include <ctime>
#include <QFile>
#include <QTextStream>
#include "base.h"

class Game : public QObject
{
    Q_OBJECT
public:
    Game();
    void Generation(QGraphicsScene *game_screen);

    //void setBlock(int xPos, int yPos, QGraphicsScene *game_screen);
};

#endif // GAME_H
