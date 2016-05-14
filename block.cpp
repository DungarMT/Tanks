#include "block.h"




/*Block::Block(int xPos, int yPos)
{
    block=new QGraphicsRectItem();
    block->setRect(xPos, yPos, 32, 32);

}

QGraphicsRectItem *Block::getBlock()
{
    return block;
}*/

Block::Block(int xPos, int yPos, QWidget *parent, QGraphicsScene *scene)
    : QGraphicsRectItem()
{
    this->setRect(xPos, yPos, 32, 32);
    scene->addItem(this);
}
