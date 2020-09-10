//
// Created by sakamoto on 10/09/20.
//

#ifndef MYFIRSTSFMLGAME_CAR_H
#define MYFIRSTSFMLGAME_CAR_H
#include <SFML/Graphics.hpp>

class Car {
    float PosX , PosY ;
    float VelX , VecY ;
    float Angle ;
    float AcX , AcY ;
    sf::Color CarColor;

public :
    Car(int X ,int Y , sf::Color CaCol){
        PosX = X , PosY = Y ;
        CarColor = CaCol ;
        Angle = 0 ;
        VelX = 0 , VecY = 0 ;
        AcX = 0 , AcY = 0 ;
    }

    sf::Color GetColour(){ return CarColor; }

    float GetX(){ return PosX; }

    float GetY(){ return PosY; }

    float  GetAngle(){ return Angle;}

    void MoveForward();

    void RotateLeft();

    void RotateRight();

    void MoveBack();

};


#endif //MYFIRSTSFMLGAME_CAR_H
