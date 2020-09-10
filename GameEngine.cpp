//
// Created by sakamoto on 10/09/20.
//

#include "GameEngine.h"
#include <iostream>
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
    for(auto &i : Cars){
        i.Move();
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

    static int frw = 10 ;

    float X1 = Cars[0].GetX() , X2 = Cars[1].GetX();
    float Y1 = Cars[0].GetY() , Y2 = Cars[1].GetY();

    std::cout << " X1 " << X1 << "  Y1 " << Y1 << '\n';
    std::cout << " X2 " << X2 << "  Y2 " << Y2 << '\n';

    float Per = Y2-Y1+0.0001 , Base = X2-X1+0.0001;

    float Angle = std::atan(abs(Per/Base))*180.0/M_PI;
    float CAngle = Cars[0].GetAngle();

    if(Per < 0 && Base < 0 ) Angle = 180.0 +   Angle ;
    else if(Base < 0  ) Angle = 180.0 - Angle ;
    else if(Per < 0) Angle = 360 - Angle ;

    float Clockwise , AntiClockWise ;

    AntiClockWise = Angle - CAngle ;
    if(AntiClockWise < 0)  AntiClockWise += 360 ;

    Clockwise = 360 - AntiClockWise ;
    if(Clockwise <= AntiClockWise && Clockwise > 2){
        Cars[0].RotateLeft();
    }
    else if (Clockwise > AntiClockWise && AntiClockWise > 2){
        Cars[0].RotateRight();
    }
    if(frw > 0) {
        Cars[0].ForwardPress();
        frw--;
    }
    else{
        Cars[0].BackwardPress();
        Cars[0].BackwardPress();
        frw += 8 ;
    }

}

 void GameEngine::CheckForCollision() {

}

void GameEngine::GameLoop() {
    while(App->isOpen()){
        sf::Event Key ;
        while(App->pollEvent(Key)) {

            if (Key.type == sf::Event::Closed) {
                Clean();
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                Cars[1].ForwardPress();
            }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            Cars[1].BackwardPress();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                Cars[1].RotateLeft();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            Cars[1].RotateRight();
        }
        UpdateComputerCar();
        CheckForCollision();
        std::cout << Cars[1].GetX() << " " << Cars[1].GetY() << '\n';
        Render();
    }
}




void  GameEngine::Clean() {
    App->close();
    delete App ;
    exit(0);
}