#ifndef PLAYER_H
#define PLAYER_H

#include <tank.h>
#include <QKeyEvent>

class Player : public Tank
{
private:
    int stars=0;
public:
    Player(char side);
    void keyPressEvent(QKeyEvent * event);
};
#endif // PLAYER_H
