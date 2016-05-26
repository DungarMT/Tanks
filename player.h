#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QList>
#include <QKeyEvent>
#include <QTimer>

class GameMap;

class Player : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Player(int xPos, int yPos, GameMap *map, QObject *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    GameMap *map;
    QList<int> *queue;
    QTimer *timer;
    int count;
    int pressKey;

signals:

public slots:

private slots:
    void move();
};

#endif // PLAYER_H
