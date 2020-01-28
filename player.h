#ifndef PLAYER_H
#define PLAYER_H

#include "ship.h"

//Specific class which will read config file
class Player : public Ship
{
public:
    Player(std::string size, std::string color, int coord,
           std::string filename, BulletFactory* bulletFactory,
           std::string inputs, int height, int width);

/*********** PLAYER MOVEMENT FUNCTIONS ************/
    // iterates thru config input (later: actual keyboard)

public slots:
    void nextFrame();

private:
    char keyInput();
    void resetIterator();
    std::string inputs; //config inputs.
    int iterator;

    // this counter can be removed once we have Actual Keyboard Inputs.
    int counter;
    int maxCounter = 25; //magic number.

};


#endif // PLAYER_H
