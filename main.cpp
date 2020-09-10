#include <iostream>
#include <SFML/Graphics.hpp>
//#include <thread>
#include "GameEngine.h"


int main() {

    GameEngine *CarGame = new GameEngine();

    CarGame->Initialise();
    CarGame->AddCar(1024/2-30-96,720/2-48-27,sf::Color::Cyan);
    CarGame->GameLoop();
    CarGame->Clean();
    return 0;
}
