#ifndef ICE_H
#define ICE_H


#include <QGraphicsRectItem>

class Ice : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Ice(int xPos, int yPos, QObject *parent = 0);
};

#endif // ICE_H
