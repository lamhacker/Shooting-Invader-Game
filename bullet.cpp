#include "bullet.h"

#include <QSound>

Bullet::Bullet(int speed, int bx, int by, int damage, std::string filename,
               std::list<Bullet*> *inbullets) :
    QObject(), speed(speed), bx(bx), by(by), damage(damage), bullets(inbullets)
{
    this->bulletImage.load(":/rsc/data/" + QString::fromStdString(filename) + ".png");

    //plays a sound when you init it!
    QSound::play(":/rsc/data/" + QString::fromStdString(filename) + ".wav");

    //calculate the boundaries for this bullet. This is based on a player fired bullet.
    setBoundary();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);
}

Bullet::~Bullet() {
    delete timer;
}


/********************* GETTERS ************************************/

int Bullet::getX() const {
    return bx;
}

int Bullet::getY() const{
    return by;
}

QPixmap Bullet::getImage() const {
    return bulletImage;
}

/************************ GAME PAUSING ***************************/
void Bullet::stop() {
    timer->stop();
}

void Bullet::start() {
    timer->start();
}

/********************** ANIMATION ********************************/

// This function sets boundary for player bullets.
//  An alien bullet heads in the opposite direction;
//  i.e., alien would be canvas + image.height.
void Bullet::setBoundary() {
    maxHeight = 0 - bulletImage.height();
}

//Removes itself from the list of bullets created, then kill itself :(
void Bullet::deleteSelf() {
    bullets->remove(this);
    //At this point no other object will be referencing <self> so it's fine.
    delete this;
}

//this will be <= for an enemy ship.
bool Bullet::inFrame(int y) {
    return (y >= maxHeight);
}

// in future we could have special bullets (which changes bx)
void Bullet::nextFrame() {
    int newBy = by + (speed);

    //if this makes the bullet is out of frame (or later, collided) then delete it..
    if(!inFrame(newBy)) {
       deleteSelf();
    } else {
        by = newBy;
    }

}


