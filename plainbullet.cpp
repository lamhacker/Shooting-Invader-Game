#include "plainbullet.h"

PlainBullet::PlainBullet(int speed, int bx, int by, int damage, std::string path
                         , std::list<Bullet*> *bullets)
    : Bullet(speed, bx, by, damage, path, bullets)
{
}
