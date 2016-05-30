#include "gamemap.h"

#include <QTextStream>

GameMap::GameMap(QGraphicsScene *workScene, QObject *parent) : QObject(parent)
{
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            map[i][j] = 0;
    this->workScene = workScene;
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

void GameMap::checkCoord(int xPos, int yPos, char side)
{
    int n=rand()%4;
    char s;
    switch (n) {
    case 0:
        s='D';
        break;
    case 1:
        s='L';
        break;
    case 2:
        s='U';
        break;
    case 3:
        s='R';
        break;
    default:
        break;
    }



    switch (s) {
    case 'D':
        if(side!='U')
        if(yPos==24){
            break;
        }
        else{
            if(map[xPos][yPos+2]==0 and map[xPos+1][yPos+2]==0){
                emit motion(s, true);
                return;
            }
            else{
                break;
            }
        }
        break;
    case 'L':
        if(side!='R')
        if(xPos==0){
            break;
        }
        else{
            if(map[xPos-1][yPos]==0 and map[xPos-1][yPos+1]==0){
                emit motion(s, true);
                return;
            }
            else{
                break;
            }
        }
        break;
    case 'U':
        if(side!='D')
        if(yPos==0){
            break;
        }
        else{
            if(map[xPos][yPos-1]==0 and map[xPos+1][yPos-1]==0){
                emit motion(s, true);
                return;
            }
            else{
                break;

            }
        }
        break;
    case 'R':
        if(side!='L')
        if(xPos==24){
            break;
        }
        else{
            if(map[xPos+2][yPos]==0 and map[xPos+2][yPos+1]==0){
                emit motion(s, true);
                return;
            }
            else{
                break;
            }
        }
        break;
    default:
        break;
    }










    switch (side) {
    case 'D':
        if(yPos==24){
            emit motion(side, false);
        }
        else{
            if(map[xPos][yPos+2]==0 and map[xPos+1][yPos+2]==0){
                emit motion(side, true);
            }
            else{
                emit motion(side, false);
            }
        }
        break;
    case 'L':
        if(xPos==0){
            emit motion(side, false);
        }
        else{
            if(map[xPos-1][yPos]==0 and map[xPos-1][yPos+1]==0){
                emit motion(side, true);
            }
            else{
                emit motion(side, false);
            }
        }
        break;
    case 'U':
        if(yPos==0){
            emit motion(side, false);
        }
        else{
            if(map[xPos][yPos-1]==0 and map[xPos+1][yPos-1]==0){
                emit motion(side, true);
            }
            else{
                emit motion(side, false);
            }
        }
        break;
    case 'R':
        if(xPos==24){
            emit motion(side, false);
        }
        else{
            if(map[xPos+2][yPos]==0 and map[xPos+2][yPos+1]==0){
                emit motion(side, true);
            }
            else{
                emit motion(side, false);
            }
        }
        break;
    default:
        break;
    }



}

void GameMap::changeCoord(int xPos, int yPos, char side)
{
    switch (side) {
    case 'D':
        map[xPos][yPos]=0;
        map[xPos+1][yPos]=0;
        map[xPos][yPos+2]=9;
        map[xPos+1][yPos+2]=9;
        break;
    case 'L':
        map[xPos][yPos]=0;
        map[xPos][yPos+1]=0;
        map[xPos-1][yPos]=9;
        map[xPos-1][yPos+1]=9;
        break;
    case 'U':
        map[xPos][yPos+1]=0;
        map[xPos+1][yPos+1]=0;
        map[xPos][yPos-1]=9;
        map[xPos+1][yPos-1]=9;
        break;
    case 'R':
        map[xPos][yPos]=0;
        map[xPos][yPos+1]=0;
        map[xPos+2][yPos]=9;
        map[xPos+2][yPos+1]=9;
        break;
    default:
        break;
    }
}

void GameMap::loadMap()
{
    qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
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
    Enemy *en = new Enemy(4,0,this);
    connect(this,SIGNAL(motion(char,bool)),en,SLOT(motion(char,bool)));
    connect(en,SIGNAL(checkCoord(int,int,char)),this, SLOT(checkCoord(int,int,char)));
    connect(en,SIGNAL(changeCoord(int,int,char)),this, SLOT(changeCoord(int,int,char)));
            workScene->addItem(en);










}
