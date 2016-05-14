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

    screen->setFixedSize(600, 600);
    game_screen->setSceneRect(0, 0, 800, 600);

    player->setPos(screen->width()/2, screen->height() - player->rect().height()-5);

    Brick *block = new Brick(100,100,game_screen);

}
/*
void Game::setBlock(int xPos, int yPos, QGraphicsScene *game_screen)
{
    Block *block_one = new Block(xPos,yPos,NULL,game_screen);
    Block *block_two = new Block(xPos+16,yPos,NULL,game_screen);
    Block *block_three = new Block(xPos,yPos+16,NULL,game_screen);
    Block *block_four = new Block(xPos+16,yPos+16,NULL,game_screen);
}
*/
