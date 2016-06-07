#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QList>
#include <QKeyEvent>
#include <QTimer>
#include <QList>
#include <typeinfo>

#include "stars.h"
#include "helmet.h"

class Player : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Player(int xPos, int yPos, QObject *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void spawnShiledPlayer();
private:
    int stars;
    int xPos, yPos, posX, posY;
    QList<int> *queue;
    int direction;
    char side;
    QTimer *timer;
    int count;
    int pressKey;
    bool animation;
    QTimer *delShield;
    bool shield;
    void changeView(int);

signals:
    void moveShield(char);
    void spawnShield(int,int);
    void changeCoord(int, int);
    void checkCoord(int, int, int, bool&);
    void spawnBullet(int, int, char, int);
private slots:
    void CheckShield();
    void deleteShield();
    void move();


};

#endif // PLAYER_H
