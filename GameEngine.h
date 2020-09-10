//
// Created by sakamoto on 10/09/20.
//

#ifndef MYFIRSTSFMLGAME_GAMEENGINE_H
#define MYFIRSTSFMLGAME_GAMEENGINE_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Car.h"
#include <math.h>

const std::string B_PATH = "Assets/bg.png";
const std::string C_PATH = "Assets/car.png";

class GameEngine {
    float CarWidth , CarHeight ;
    std::pair<float,float> TrackTL , TrackDR ;
    sf::RenderWindow *App ;
    sf::Texture CarTexture , BackgroundTexture;
    sf::Sprite CarS , BackS;
    std::vector<Car> Cars;
public :

    //Initilize The Window , Textures
    void Initialise() ;

    //Render
    void Render();

    void GameLoop();

    void Clean();

    void AddCar(float X , float Y , sf::Color CarCol);

    void UpdateComputerCar();

    void CheckForCollision();


};


#endif //MYFIRSTSFMLGAME_GAMEENGINE_H
