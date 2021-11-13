#include <SFML/Graphics.hpp>
#include "Game.h"


using namespace std;
using namespace sf;

int main()
{
    srand(time(0));
    Game game;
    game.run();

    return 0;
}