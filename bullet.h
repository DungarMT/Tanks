#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QPainter>
#include <QList>
#include <typeinfo>

#include "concrete.h"
#include "brick.h"
#include "enemy.h"
#include "base.h"
#include "player.h"

class Bullet : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    int count;
    int xPos;
    int yPos;
    char side;
    QTimer *timer;
    int BulletId;
    static int StaticId;
public:
    explicit Bullet(int xPos, int yPos, char side, QObject *parent = 0);
signals:
    void spawnExplosion(int,int,bool);
public slots:

    void move();
};

#endif // BULLET_H
