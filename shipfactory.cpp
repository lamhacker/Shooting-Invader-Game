#include "shipfactory.h"

#include "player.h"

ShipFactory::ShipFactory(){}

void ShipFactory::set(BulletFactory* bulletFactory, int windowHeight, int windowWidth) {
    this->bulletFactory = bulletFactory;
    this->windowHeight = windowHeight;
    this->windowWidth = windowWidth;
}

Ship* ShipFactory::createShip(std::string size, std::string color, int coord, std::string inputs) {
    //some input parameter will decide what to build
    Ship *result = NULL;

    std::string filename = "DogInvader";

    //currently there is only one ship so this function is fairly basic and almost singleton like.
    // in future, we may update Ship into a builder type, depending on Stage 3 Upgrades?

    result = new Player(size, color, coord, filename, bulletFactory, inputs, windowHeight, windowWidth);
    return result;
}
