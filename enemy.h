#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QTimer>

class Enemy: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Enemy(int xPos, int yPos, QObject *parent = 0);
private:
    bool animation;
    int xPos, yPos;
    static int StaticId;
    int EnemyId;
    char side;
    int count;
    QTimer *timer;
    QTimer *timerAnimation;

signals:
    checkCoord(int,int,char, int);
    changeCoord(int,int,char, int);
private slots:
    void TankAnimation();
    void move();
    void motion(char side ,bool flag, int id);
};

#endif // ENEMY_H
