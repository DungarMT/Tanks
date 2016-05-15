#include "game.h"

Game::Game()
{
    srand(time(0));
    //Create main game scene
    QGraphicsScene *game_screen = new QGraphicsScene(this);

    //Create player tank
    Player *player = new Player('U');
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

    player->setPos(screen->width()/2+1, screen->height() - player->rect().height()-5);

    Upgrades *strs1 = new Upgrades(rand()%600,rand()%600,game_screen);
    Upgrades *strs2 = new Upgrades(rand()%600,rand()%600,game_screen);
    Upgrades *strs3 = new Upgrades(rand()%600,rand()%600,game_screen);


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

