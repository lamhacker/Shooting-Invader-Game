#ifndef BULLETFACTORY_H
#define BULLETFACTORY_H

#include "bullet.h"

#include <map>

class BulletFactory
{
public:
    BulletFactory();
    void set(int windowHeight, int windowWidth);
    //Factory functions.
    void makeBullet(int speed, int x, int y, int damage, std::string type, bool isPlayer);

    std::list<Bullet*> bullets;
private:
    int windowHeight;
    int windowWidth;


};

#endif // BULLETFACTORY_H
