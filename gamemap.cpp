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
    Player *player = new Player(xPos, yPos, this, this);
    workScene->addItem(player);
}

void GameMap::loadMap()
{
    QFile file("D:\\Projects\\Tanks\\1.txt");
    file.open(QIODevice::ReadOnly);
    QString tmp;
    QTextStream in(&file);
    for(int y = 0; y < 26; y++)
        for(int x = 0; x < 26; x++){
            in >> tmp;
            if(tmp.toInt() == 1 and tmp.toInt() != map[x][y]){
                this->createPlayer(x, y);
            }
            if(tmp.toInt() != map[x][y])
                map[x][y] = tmp.toInt();
        }


}
