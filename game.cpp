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
    setBlock(300,300, game_screen);
    setBlock(400,400, game_screen);

}

void Game::setBlock(int xPos, int yPos, QGraphicsScene *game_screen)
{
    Block *block_one = new Block(xPos,yPos,NULL,game_screen);
    Block *block_two = new Block(xPos+16,yPos,NULL,game_screen);
    Block *block_three = new Block(xPos,yPos+16,NULL,game_screen);
    Block *block_four = new Block(xPos+16,yPos+16,NULL,game_screen);
}
