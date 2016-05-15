#include "game.h"

Game::Game()
{
    //Create main game scene
    QGraphicsScene *game_screen = new QGraphicsScene(this);

    //Create player tank
    Player *player = new Player('U');
    player->setRect(0, 0, 30, 30);

    game_screen->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    QGraphicsView *screen = new QGraphicsView(game_screen);
    screen->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    screen->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    screen->show();

    screen->setFixedSize(800, 600);
    game_screen->setSceneRect(0, 0, 800, 600);

    player->setPos(screen->width()/2, screen->height() - player->rect().height()-5);




    QVector <Block *> block;
    block.push_back(new Block(300,300,game_screen,1));
    block.push_back(new Block(300,333,game_screen,1));
    block.push_back(new Block(300,366,game_screen,1));
    block.push_back(new Block(333,300,game_screen,5));
    block.push_back(new Block(333,333,game_screen,2));
    block.push_back(new Block(333,366,game_screen,3));
    block.push_back(new Block(366,300,game_screen,1));
    block.push_back(new Block(366,333,game_screen,1));
    block.push_back(new Block(366,366,game_screen,1));


}

