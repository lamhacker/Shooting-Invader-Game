#include "player.h"

Player::Player(std::string size, std::string color, int coord,
               std::string filename, BulletFactory* bulletFactory,
               std::string inputs, int height, int width)
    : Ship(size, color, coord, filename, bulletFactory, height, width)
{
    this->inputs = inputs;
    this->iterator = 0;
    this->counter = 1;
}

void Player::resetIterator() {
    if (iterator >= inputs.length()) {
        iterator = 0;
    }
}

// NOTE: IN FUTURE WE WON'T READ THE INPUT MOVEMENTS LIKE THIS;
//INSTEAD WE SHOULD USE QEvent - please read QEvent and KeyEvent documentation
//You can replace this as needed; though config may in future contain what keys
//to use E.g., Ship1 uses WASD instead of Left/right buttons.
//Iterate through input. Each L or R will move 3*maxCounter pixels
//if it shoots, move the iterator - only shoot 1 bullet.
char Player::keyInput() {
    //reset iterator if necessary - we infinitely loop input string.
    resetIterator();

    //check what letter it is (future:check what letter)
    char move = inputs.at(iterator);
    if (move == 'S') {
        iterator++;
        return move;
    }
    //counter checks and move iterator when appropriate
    if (counter == maxCounter) {
        //reset the counter and move the iterator up
        counter = 1;
        iterator++;
    } else {
        counter++;
    }

    return move;
}

//NOTE: if we ever add vertical movement please adjust.
void Player::nextFrame(){
    //edit x or spawn a bullet.
    char move = keyInput();
    if (move == 'L') {
        x = adjustX(x - 3);
    } else if (move == 'R') {
        x = adjustX(x + 3);
    }  else if (move == 'S') {
        //there is currently only one bullet type...
       bulletFactory->makeBullet(20, (x + shipImage.width()/ 2), y, 10, "PlainBullet", true);

    }

}

