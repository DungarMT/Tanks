#ifndef UPGRADES_H
#define UPGRADES_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>

class Upgrades : public QGraphicsRectItem
{
public:
    Upgrades(int xPos, int yPos, QGraphicsScene *scene);
};

#endif // UPGRADES_H
