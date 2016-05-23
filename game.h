#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>

#include "gamemap.h"

class Game : public QObject
{
    Q_OBJECT
public:
    Game();
};

#endif // GAME_H
