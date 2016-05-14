#ifndef BRICK_H
#define BRICK_H

#include "block.h"

class Brick : public Block
{
public:
    Brick(int xPos, int yPos, QGraphicsScene *scene);
};

#endif // BRICK_H
