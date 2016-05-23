#ifndef BUSH_H
#define BUSH_H


#include <QGraphicsRectItem>
#include <QBrush>

class Bush : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Bush(int xPos, int yPos, QObject *parent = 0);
};

#endif // BUSH_H
