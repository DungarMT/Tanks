#include "block.h"


/*
Block::Block(int xPos, int yPos, QWidget *parent, QGraphicsScene *scene)
{
    //scene->addItem(this);
    Block *block_one = new Block(xPos,yPos,scene);
    Block *block_two = new Block(xPos+16,yPos,scene);
    Block *block_three = new Block(xPos,yPos+16,scene);
    Block *block_four = new Block(xPos+16,yPos+16,scene);
}


Block::Block(int xPos, int yPos, QGraphicsScene *scene)
    : QGraphicsRectItem()
{
    this->setRect(xPos, yPos, 16, 16);
    scene->addItem(this);
}
*/
Block::Block(int xPos, int yPos, QGraphicsScene *scene, int IdBlock)
{
    switch (IdBlock) {
    case 1:
       Brick(xPos, yPos, scene, NULL);
        break;
    case 2:
        Concrete(xPos,yPos,scene,NULL);
        break;
    case 3:
        Bush(xPos,yPos,scene,NULL);
        break;
    case 4:
        Ice(xPos,yPos,scene,NULL);
        break;
    default:
        break;
    }
}
