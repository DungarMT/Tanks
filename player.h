#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>

class Player : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = 0);

signals:

public slots:
};

#endif // PLAYER_H
