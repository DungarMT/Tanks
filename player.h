#ifndef PLAYER_H
#define PLAYER_H

#include <tank.h>
#include <QKeyEvent>

class Player : public Tank
{
public:
    Player(char side);
    void keyPressEvent(QKeyEvent * event);
};
#endif // PLAYER_H
