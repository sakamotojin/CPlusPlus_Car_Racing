//
// Created by sakamoto on 10/09/20.
//

#include "GameEngine.h"

#define X first
#define Y second

void GameEngine::Initialise() {

    CarWidth = 96 , CarHeight = 48 ;
    TrackTL.X = 35 , TrackTL.Y = 29 ;

    App  = new sf::RenderWindow(sf::VideoMode(1024 , 720 ), "Sakamoto Car Racing");
    App->setFramerateLimit(60);
    BackgroundTexture.loadFromFile(B_PATH);
    CarTexture.loadFromFile(C_PATH);
    CarTexture.setSmooth(true);
    CarS.setTexture(CarTexture);
    BackS.setTexture(BackgroundTexture);
    BackS.scale(1.6,1.5);
    CarS.scale(0.1,0.1);
    AddCar(815,305,sf::Color::Red);
}
void GameEngine::Render() {
    App->clear();
    App->draw(BackS);
    for(auto i : Cars){
        CarS.setPosition(i.GetX(), i.GetY());
        CarS.setColor(i.GetColour());
        CarS.setRotation(i.GetAngle());
        App->draw(CarS);
    }
    App->display();
}

void GameEngine::AddCar(float X , float Y , sf::Color CarCol){
    Cars.push_back(Car(X,Y,CarCol));
}

void GameEngine::UpdateComputerCar() {

}

 void GameEngine::CheckForCollision() {

}

void GameEngine::GameLoop() {
    while(App->isOpen()){
        sf::Event Key ;
        while(App->pollEvent(Key)){}

        if(Key.type == sf::Event::Closed){
                Clean();
            }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                Cars[1].MoveForward();
            }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            Cars[1].MoveBack();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                Cars[1].RotateLeft();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            Cars[1].RotateRight();
        }
        UpdateComputerCar();
        CheckForCollision();
        Render();
    }
}




void  GameEngine::Clean() {
    App->close();
    delete App ;
    exit(0);
}