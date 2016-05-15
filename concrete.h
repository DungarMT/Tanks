#ifndef CONCRETE_H
#define CONCRETE_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>

class  Concrete : public QGraphicsRectItem
{
public:
    Concrete(int xPos, int yPos, QGraphicsScene *scene, QWidget *parent);
    Concrete(int xPos, int yPos, QGraphicsScene *scene);
};

#endif // CONCRETE_H
