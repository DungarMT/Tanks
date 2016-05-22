#include "gamemap.h"

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
    Player *player = new Player(this);
    player->setRect(xPos * 16, yPos * 16, 32, 32);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    workScene->addItem(player);
}
