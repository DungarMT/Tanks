#ifndef BASE_H
#define BASE_H


#include <QGraphicsRectItem>
#include <QPainter>

class Base : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Base(int xPos, int yPos, QObject *parent = 0);
};

#endif // BASE_H
