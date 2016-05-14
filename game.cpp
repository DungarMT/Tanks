#include "game.h"

Game::Game()
{
    //Create main game scene
    QGraphicsScene *game_screen = new QGraphicsScene(this);

    //Create player tank
    Player *player = new Player();
    player->setRect(0, 0, 100, 100);

    game_screen->addItem(player);

    player->setFocus();

    QGraphicsView *screen = new QGraphicsView(game_screen);
    screen->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}
