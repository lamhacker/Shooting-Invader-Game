#ifndef SHIPFACTORY_H
#define SHIPFACTORY_H

#include "bulletfactory.h"
#include "ship.h"

#include <string>

//Factory class for making player ships.
class ShipFactory
{
public:
    ShipFactory();
    void set(BulletFactory* bulletFactory, int windowHeight, int windowWidth);
    //return a ship
    Ship* createShip(std::string size, std::string color, int coord, std::string inputs);

private:
    BulletFactory* bulletFactory; //ptr to the factory
    int windowHeight;
    int windowWidth;

};

#endif // SHIPFACTORY_H
