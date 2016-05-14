#include <QApplication>
#include "game.h"
//yay
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game game;

    return a.exec();
}
