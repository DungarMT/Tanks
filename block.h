#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>


class Block : public QGraphicsRectItem
{

private:
//    QGraphicsRectItem * block;
public:
    Block(int xPos, int yPos, QWidget *parent, QGraphicsScene *scene);
//    QGraphicsRectItem* getBlock();
};

#endif // BLOCK_H
