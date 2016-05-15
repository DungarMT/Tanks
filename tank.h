#ifndef TANK_H
#define TANK_H
#include <QGraphicsRectItem>

class Tank : public QGraphicsRectItem
{
public:
    Tank(char side);

protected:
    char side;
};

#endif // TANK_H
