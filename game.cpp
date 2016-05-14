#include "game.h"

Game::Game()
{
    //Create main game scene
    QGraphicsScene *game_screen = new QGraphicsScene(this);

    //Create player tank
    Player *player = new Player();
    player->setRect(0, 0, 32, 32);

    game_screen->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    QGraphicsView *screen = new QGraphicsView(game_screen);
    screen->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    screen->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    screen->show();
    screen->setFixedSize(800, 600);
    game_screen->setSceneRect(0, 0, 800, 600);

    player->setPos(screen->width()/2, screen->height() - player->rect().height());

    screen->setFixedSize(600, 600);
    game_screen->setSceneRect(0, 0, 800, 600);

    player->setPos(screen->width()/2, screen->height() - player->rect().height()-5);

    Block *block = new Block(100,100, NULL, game_screen);

}
