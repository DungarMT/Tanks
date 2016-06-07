#ifndef SHIELD_H
#define SHIELD_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QTimer>

class Shield : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    QTimer *animationTimer;
    bool animate;
    QTimer *deleted;
public:
    explicit Shield(int xPos, int yPos, QObject *parent = 0);
private slots:
    void animation();
    void move(char side);
    void del();
};

#endif // SHIELD_H
