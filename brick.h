#ifndef BRICK_H
#define BRICK_H

#include <QGraphicsRectItem>
#include <QPainter>

class Brick : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Brick(int xPos, int yPos, QObject *parent = 0);
};

#endif // BRICK_H
