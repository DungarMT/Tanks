#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QList>
#include <typeinfo>

class Bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet(char side);

private:
    char side;
public slots:
    void move();
};

#endif // BULLET_H
