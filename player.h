#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QList>
#include <QKeyEvent>
#include <QTimer>

class Player : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Player(int xPos, int yPos, QObject *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    int xPos, yPos, posX, posY;
    QList<int> *queue;
    int direction;
    char side;
    QTimer *timer;
    int count;
    int pressKey;
    bool animation;

    void changeView(int);

signals:
    void changeCoord(int, int);
    void checkCoord(int, int, int, bool&);
    void spawnBullet(int, int, char);
public slots:

private slots:
    void move();

};

#endif // PLAYER_H
