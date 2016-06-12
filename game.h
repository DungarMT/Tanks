#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "gamemap.h"

class Game : public QObject
{
    Q_OBJECT
public:
    Game();
private:
    int points;
public slots:
    void addPoints(int count);
};

#endif // GAME_H
