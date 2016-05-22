#ifndef PLAYER_H
#define PLAYER_H

#include <tank.h>
#include <QKeyEvent>
#include <QTimer>

class Player : public QObject, public Tank
{
    Q_OBJECT
private:
    int stars;
    int count;
    bool processEvent;
    QTimer *timer;
public:
    Player(char side);
    void keyPressEvent(QKeyEvent * event);

private slots:
    void move();
};
#endif // PLAYER_H
