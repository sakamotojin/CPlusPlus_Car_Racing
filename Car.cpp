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

void Car::ForwardPress() {
    VelX += 1*cos((Angle*M_PI)/180.0);
    VelY += 1*sin((Angle*M_PI)/180.0);
}

void Car::BackwardPress() {
    VelX -= 1*cos((Angle*M_PI)/180.0);
    VelY -= 1*sin((Angle*M_PI)/180.0);
}

void Car::Move() {
    PosX += VelX ;
    PosY += VelY;
    VelX *= 0.95;
    VelY *= 0.95;
}