#include "game.h"

Game::Game()
{
    //Create main game scene
    QGraphicsScene *game_screen = new QGraphicsScene(this);
    game_screen->setSceneRect(0, 0, 800, 600);

    //Create player tank
    Player *player = new Player();
    player->setRect(200, 5, 32, 32);

    game_screen->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    QGraphicsView *screen = new QGraphicsView(game_screen);
    screen->setFixedSize(600, 600);
    screen->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    screen->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    screen->show();

}
