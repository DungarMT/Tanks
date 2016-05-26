#include "player.h"

Player::Player(int xPos, int yPos, GameMap *map, QObject *parent) : QObject(parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPen(Qt::NoPen);
    setRect(xPos * 16, yPos * 16, 32, 32);
    setBrush(QPixmap(":/img/player1up.png"));
    this->setZValue(1);
    this->map = map;
    queue = new QList<int>();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    count = 0;
    pressKey = 0;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
        event->ignore();
    else{
        switch(event->key()){
        case Qt::Key_Up:
            if(queue->size() < 2)
                queue->push_back(event->key());
            break;
        }
    }
    if(!timer->isActive()){
        timer->start(20);
    }
}
void Player::keyReleaseEvent(QKeyEvent *event)
{

    if(event->isAutoRepeat())
    {
        event->ignore();
    }
    else
    {
        switch(event->key()){
        case Qt::Key_Up:
            if(queue->first() == Qt::Key_Up){
                   //timer->stop();
                queue->pop_front();
            }
            else if(queue->last() == Qt::Key_Up){
                queue->pop_back();
            }
            break;
        }
    }
}

void Player::move()
{

    if(!queue->isEmpty()){
        switch(queue->last()){
        case Qt::Key_Up:
            setPos(x(), y()-2);
            count++;
            break;
        }
    }

    /*
    if(count >=8){
       count = 0;
       timer->stop();
    }
    */
}
