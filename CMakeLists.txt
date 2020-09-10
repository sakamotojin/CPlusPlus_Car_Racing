cmake_minimum_required(VERSION 3.17)
project(MyFirstSFMLGame)

set(CMAKE_CXX_STANDARD 17)


add_executable(MyFirstSFMLGame main.cpp GameEngine.cpp GameEngine.h Car.cpp Car.h MathsUtil.h MathsUtil.cpp)