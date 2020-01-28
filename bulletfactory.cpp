#include "bulletfactory.h"
#include "bullet.h"
#include "plainbullet.h"

BulletFactory::BulletFactory() {}

void BulletFactory::set(int windowHeight, int windowWidth) {
    this->windowHeight = windowHeight;
    this->windowWidth = windowWidth;

}


//change the method signature once 1) there are different bullet types
void BulletFactory::makeBullet(int speed, int x, int y, int damage, std::string bType, bool isPlayer)
{
    //depending on the input, will make a bullet
    Bullet *result = NULL;

    //If it is a player bullet, change speed to -ve
    if (isPlayer) {
        speed = (-1) * speed;
    }

    //Right now, there is only 1 thing that can make bullets; change this later
    if (bType == "PlainBullet") {
        result = new PlainBullet(speed, x, y, damage, bType, &bullets);
        bullets.push_front(result);
    } // if it were an enemy bullet we would put that in a differet statement here

}
