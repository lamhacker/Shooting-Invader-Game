#ifndef PLAINBULLET_H
#define PLAINBULLET_H

#include "bullet.h"

#include <list>
#include <string>

//in future this class may have more unique features
//e.g., we might add a 'curve bullet'
//which curves and hence travels in different directions.
class PlainBullet : public Bullet
{
public:

    PlainBullet(int speed, int bx, int by, int damage,
                std::string path,
                std::list<Bullet*> *bullets);


};

#endif // PLAINBULLET_H
