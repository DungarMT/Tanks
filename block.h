#ifndef BLOCK_H
#define BLOCK_H

#include "brick.h"
#include "concrete.h"
#include "bush.h"
#include "ice.h"

class Block
{

private:
//    QGraphicsRectItem * block;
public:
    Block(int xPos, int yPos, QGraphicsScene *scene, int IdBlock);
    /*
    Block(int xPos, int yPos, QWidget *parent, QGraphicsScene *scene);
    Block(int xPos, int yPos, QGraphicsScene *scene);
    */
//    QGraphicsRectItem* getBlock();

};

#endif // BLOCK_H
