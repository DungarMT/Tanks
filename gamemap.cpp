#include "gamemap.h"

#include <QTextStream>

GameMap::GameMap(QGraphicsScene *workScene, QObject *parent) : QObject(parent)
{
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            map[i][j] = 0;
    this->workScene = workScene;
    animationTimer = new QTimer(this);
    animationTimer->start(1000);
}

void GameMap::createPlayer(int xPos, int yPos)
{
    map[xPos][yPos] = 1;
    map[xPos+1][yPos] = 1;
    map[xPos][yPos+1] = 1;
    map[xPos+1][yPos+1] = 1;
    Player *player = new Player(xPos, yPos, this);
    workScene->addItem(player);
    connect(player, SIGNAL(changeCoord(int,int)), this, SLOT(changePlayerCoord(int,int)));
    connect(player, SIGNAL(checkCoord(int,int,int,bool&)), this, SLOT(checkPlayerCoord(int,int,int,bool&)));
}

void GameMap::createBase(int xPos, int yPos)
{
    map[xPos][yPos] = 7;
    map[xPos+1][yPos] = 7;
    map[xPos][yPos+1] = 7;
    map[xPos+1][yPos+1] = 7;
    Base *base= new Base(xPos, yPos, this);
    workScene->addItem(base);
}

void GameMap::createBlock(int xPos, int yPos, int idBlock)
{
    switch(idBlock){
    case 2:
        {
        Brick *brick = new Brick(xPos, yPos, this);
        workScene->addItem(brick);
        break;
        }
    case 3:
        {
        Concrete *concrete = new Concrete(xPos, yPos, this);
        workScene->addItem(concrete);
        break;
        }
    case 4:
        {
        Water *water = new Water(xPos, yPos, this);
        workScene->addItem(water);
        connect(animationTimer, SIGNAL(timeout()), water, SLOT(animate()));
        break;
        }
    case 5:
        {
        Bush *bush = new Bush(xPos, yPos, this);
        workScene->addItem(bush);
        break;
        }
    case 6:
        {
        Ice *ice = new Ice(xPos, yPos, this);
        workScene->addItem(ice);
        break;
        }
        /*
    case 7:
        {
        Base *base = new Base(xPos, yPos, this);
        workScene->addItem(base);
        break;
        }
        */
    }
}

void GameMap::changePlayerCoord(int xPos, int yPos)
{
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            if(map[i][j] == 1)
                map[i][j] = 0;
    map[xPos][yPos] = 1;
    map[xPos+1][yPos] = 1;
    map[xPos][yPos+1] = 1;
    map[xPos+1][yPos+1] = 1;
}

void GameMap::checkPlayerCoord(int xPos, int yPos, int direction, bool &tmp)
{

    switch(direction){
    case Qt::Key_Up:
        if(yPos == 0){
            tmp = false;
            return;
        }
        if((map[xPos][yPos-1] == 0 or map[xPos][yPos-1] == 5)and
           (map[xPos+1][yPos-1] == 0 or map[xPos+1][yPos-1] == 5)){
            tmp = true;
            return;
        }
        break;
    case Qt::Key_Down:
        if(yPos == 24){
            tmp = false;
            return;
        }
        if((map[xPos][yPos+2] == 0 or map[xPos][yPos+2] == 5)and
           (map[xPos+1][yPos+2] == 0 or map[xPos+1][yPos+2] == 5)){
            tmp = true;
            return;
        }
        break;
    case Qt::Key_Left:
        if(xPos == 0){
            tmp = false;
            return;
        }
        if((map[xPos-1][yPos] == 0 or map[xPos-1][yPos] == 5)and
           (map[xPos-1][yPos+1] == 0 or map[xPos-1][yPos+1] == 5)){
            tmp = true;
            return;
        }
        break;
    case Qt::Key_Right:
        if(xPos == 24){
            tmp = false;
            return;
        }
        if((map[xPos+2][yPos] == 0 or map[xPos+2][yPos] == 5)and
           (map[xPos+2][yPos+1] == 0 or map[xPos+2][yPos+1] == 5)){
            tmp = true;
            return;
        }
        break;
    }
    tmp = false;
}

void GameMap::loadMap()
{
    QFile file(":/maps/1.txt");
    file.open(QIODevice::ReadOnly);
    QString tmp;
    QTextStream in(&file);
    for(int y = 0; y < 26; y++)
        for(int x = 0; x < 26; x++){
            in >> tmp;
            if(tmp.toInt() == 1 and tmp.toInt() != map[x][y])
                this->createPlayer(x, y);
            if(tmp.toInt() == 7 and tmp.toInt() != map[x][y])
                this->createBase(x,y);
            if(tmp.toInt() != map[x][y])
                map[x][y] = tmp.toInt();
            if(tmp.toInt()!=0){
                createBlock(x,y,tmp.toInt());
            }
        }


}
