#include "game.h"

Game::Game()
{
    srand(time(0));
    //Create main game scene
    QGraphicsScene *game_screen = new QGraphicsScene(this);

    //Create player tank
    Player *player = new Player('U');
    player->setRect(0, 0, 31, 31);

    game_screen->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    QGraphicsView *screen = new QGraphicsView(game_screen);
    screen->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    screen->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    screen->show();

    screen->setFixedSize(800, 600);
    game_screen->setSceneRect(0, 0, 800, 600);

    //player->setPos(screen->width()/2+1, screen->height() - player->rect().height()-5);

    player->setPos(32*4,32*12);
    //player->setPos(screen->width()/2+1, screen->height() - player->rect().height()-4);
    Generation(game_screen);




}

void Game::Generation(QGraphicsScene *game_screen)
{
    QVector <Block *> block;
    QVector <Brick *> brick;
    QVector <Concrete *> concrete;

    QFile file("C:\\file.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream readFile(&file);
    QString buff;

    int buff_x, buff_y;
    while(!readFile.atEnd()){
         buff = readFile.readLine();
         if(buff=="brick")
         {
             buff = readFile.readLine();
             buff_y=buff.toInt();
             buff = readFile.readLine();
             buff_x=buff.toInt();
             block.push_back(new Block((buff_x-1)*32,(buff_y-1)*32,game_screen,1));
        }
         else if(buff=="concrete"){
             buff = readFile.readLine();
             buff_y=buff.toInt();
             buff = readFile.readLine();
             buff_x=buff.toInt();
             block.push_back(new Block((buff_x-1)*32,(buff_y-1)*32,game_screen,2));
         }
         else if(buff=="brick-mini"){
             buff = readFile.readLine();
             buff_y=buff.toInt();
             buff = readFile.readLine();
             buff_x=buff.toInt();
             buff = readFile.readLine();
             if(buff=="\t1"){
                 brick.push_back(new Brick((buff_x-1)*32,(buff_y-1)*32,game_screen));
             }
             else if(buff=="\t2"){
                  brick.push_back(new Brick((buff_x-1)*32+16,(buff_y-1)*32,game_screen));
             }
             else if(buff=="\t3"){
                  brick.push_back(new Brick((buff_x-1)*32,(buff_y-1)*32+16,game_screen));
             }
             else if(buff=="\t4"){
                  brick.push_back(new Brick((buff_x-1)*32+16,(buff_y-1)*32+16,game_screen));
             }
         }
         else if(buff=="concrete-mini"){
             buff = readFile.readLine();
             buff_y=buff.toInt();
             buff = readFile.readLine();
             buff_x=buff.toInt();
             buff = readFile.readLine();
             if(buff=="\t1"){
                 concrete.push_back(new Concrete((buff_x-1)*32,(buff_y-1)*32,game_screen));
             }
             else if(buff=="\t2"){
                  concrete.push_back(new Concrete((buff_x-1)*32+16,(buff_y-1)*32,game_screen));
             }
             else if(buff=="\t3"){
                  concrete.push_back(new Concrete((buff_x-1)*32,(buff_y-1)*32+16,game_screen));
             }
             else if(buff=="\t4"){
                  concrete.push_back(new Concrete((buff_x-1)*32+16,(buff_y-1)*32+16,game_screen));
             }
         }

    }
    Base *base=new Base(6*32,12*32,game_screen);

    Upgrades *strs1 = new Upgrades(rand()%12*32,rand()%12*32,game_screen);
    Upgrades *strs2 = new Upgrades(rand()%12*32,rand()%12*32,game_screen);
    Upgrades *strs3 = new Upgrades(rand()%12*32,rand()%12*32,game_screen);

}

