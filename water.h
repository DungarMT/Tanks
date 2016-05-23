#ifndef WATER_H
#define WATER_H

#include <QGraphicsRectItem>
#include <QPainter>

class Water : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Water(int xPos, int yPos, QObject *parent = 0);
};

#endif // WATER_H
