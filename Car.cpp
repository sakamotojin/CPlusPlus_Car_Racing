//
// Created by sakamoto on 10/09/20.
//

#include "Car.h"
#include <iostream>
#include <math.h>

void Car::RotateRight() {
    Angle = int(Angle + 2 + 360 )%360;
    //std::cout << "Current Angle Of Car" << Angle << " \n";
}

void Car::RotateLeft() {
    Angle = int(Angle - 2 + 360 )%360;
    //std::cout << "Current Angle Of Car" << Angle << " \n";
}

void Car::MoveForward() {
    PosX += 7* std::cos((Angle*M_PI)/180.0) ;
    PosY += 7*std::sin((Angle*M_PI)/180.0);
}

void Car::MoveBack() {
    PosX += -7* std::cos((Angle*M_PI)/180.0) ;
    PosY += -7*std::sin((Angle*M_PI)/180.0);
}