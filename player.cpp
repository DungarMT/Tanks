#include "player.h"

Player::Player(int xPos, int yPos, QObject *parent) : QObject(parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPen(Qt::NoPen);
    setRect(xPos * 16, yPos * 16, 32, 32);
    setBrush(QPixmap(":/img/player1up.png"));
    this->setZValue(1);
    queue = new QList<int>();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    direction = 0;
    timer->start(20);
    count = 0;
    pressKey = 0;
    this->xPos = xPos;
    this->yPos = yPos;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Up
     ||event->key()==Qt::Key_Down
     ||event->key()==Qt::Key_Left
     ||event->key()==Qt::Key_Right){
        if(event->isAutoRepeat())
            event->ignore();
        else if(queue->size() < 2){
            if(queue->isEmpty()){
                queue->push_back(event->key());
                this->changeView(event->key());
            }
            else if(queue->first() != event->key()){
                queue->push_back(event->key());
                this->changeView(event->key());
            }
        }
    }
    else if(event->key()==Qt::Key_Space){}
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
                queue->pop_front();
            }
            else if(queue->last() == Qt::Key_Up){
                queue->pop_back();
            }
            break;
        case Qt::Key_Down:
            if(queue->first() == Qt::Key_Down){
                queue->pop_front();
            }
            else if(queue->last() == Qt::Key_Down){
                queue->pop_back();
            }
            break;
        case Qt::Key_Left:
            if(queue->first() == Qt::Key_Left){
                queue->pop_front();
            }
            else if(queue->last() == Qt::Key_Left){
                queue->pop_back();
            }
            break;
        case Qt::Key_Right:
            if(queue->first() == Qt::Key_Right){
                queue->pop_front();
            }
            else if(queue->last() == Qt::Key_Right){
                queue->pop_back();
            }
            break;
        }
    }
}

void Player::move()
{
    if(direction == 0 and !queue->isEmpty())
        direction = queue->last();
    switch(direction){
    case Qt::Key_Up:
        setPos(x(), y()-2);
        count++;
        break;
    case Qt::Key_Down:
        setPos(x(), y()+2);
        count++;
        break;
    case Qt::Key_Left:
        setPos(x()-2, y());
        count++;
        break;
    case Qt::Key_Right:
        setPos(x()+2, y());
        count++;
        break;
    }
    if(count >=8){
        switch(direction){
        case Qt::Key_Up:
            yPos--;
            emit changeCoord(xPos, yPos);
            break;
        case Qt::Key_Down:
            yPos++;
            emit changeCoord(xPos, yPos);
            break;
        case Qt::Key_Left:
            xPos--;
            emit changeCoord(xPos, yPos);
            break;
        case Qt::Key_Right:
            xPos++;
            emit changeCoord(xPos, yPos);
            break;
        }
       count = 0;
       direction = 0;
    }
}

void Player::changeView(int direction)
{
    switch(direction){
    case Qt::Key_Up:
        this->setBrush(QPixmap(":/img/player1up.png"));
        break;
    case Qt::Key_Down:
        this->setBrush(QPixmap(":/img/player1down.png"));
        break;
    case Qt::Key_Left:
        this->setBrush(QPixmap(":/img/player1left.png"));
        break;
    case Qt::Key_Right:
        this->setBrush(QPixmap(":/img/player1right.png"));
        break;
    }
}
