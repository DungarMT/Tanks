#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QPainter>


class Player : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Player(int xPos, int yPos, QObject *parent = 0);

private:


signals:

public slots:
};

#endif // PLAYER_H
