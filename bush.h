#ifndef BUSH_H
#define BUSH_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>

class Bush: public QGraphicsRectItem
{
public:
    Bush(int xPos, int yPos, QGraphicsScene *scene, QWidget *parent);
    Bush(int xPos, int yPos, QGraphicsScene *scene);
};

#endif // BUSH_H
