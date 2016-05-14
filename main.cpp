#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"

#include "block.h"
//yay

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene();

    Player *player = new Player();
    player->setRect(0, 0, 100, 100);

    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(600,600);
    scene->setSceneRect(0,0,800,600);



    Block *test=new Block(10,10, NULL, scene);
    //scene->addItem(test);



    player->setPos(view->width()/2, view->height() - player->rect().height());


    return a.exec();
}
