#include "game.h"

Game::Game()
{
    //Create main game scene
    QGraphicsScene *gameScene = new QGraphicsScene(this);

    //Create game screen, off scroll bars, show screen
    QGraphicsView *gameScreen = new QGraphicsView(gameScene);
    gameScreen->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameScreen->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameScreen->show();

    //set screen and scene size
    gameScreen->setFixedSize(800,600);
    gameScene->setSceneRect(0, 0, 800, 600);

    //Create game map
    GameMap *map = new GameMap(gameScene);
    map->createPlayer(0, 0);
}
