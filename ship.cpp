#include "ship.h"

QString Ship::fileType = ".png";
// all ships are going to use extension .png...

Ship::Ship(std::string size, std::string color, int coord, std::string filename,
           BulletFactory *bulletFactory, int height, int width)
    :  QObject(), coord(coord), bulletFactory(bulletFactory), cHeight(height), cWidth(width)
{
    path = ":/rsc/data/" + QString::fromStdString(filename);
    this->size = QString::fromStdString(size);
    this->color = QString::fromStdString(color);
    shipImage.load(path + this->size + this->color + fileType); // : denotes resource

    setBoundary();

    //fix the initial coord is a nice one if need be
    this->x = adjustX(coord);
    this->y = maxY; // TODO: change this to a proper value.


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);
}

/**************** GETTERS *************************/
int Ship::getX() const {
    return x;
}

int Ship::getY() const {
    return y;
}

QPixmap Ship::getImage() const {
    return shipImage;
}

/************* Other ****************************/
void Ship::setBoundary() {
    this->maxX = cWidth - shipImage.width();
    this->maxY = cHeight - shipImage.height();
}

//for changing the colour after paused
void Ship::setColor(QString color) {
    this->color = color;
    //now change the image
    shipImage.load(path + size + color + fileType);

}

void Ship::setSize(QString size) {
   this->size = size;
   shipImage.load(path + size + color + fileType);
   //reset teh boundaries
    setBoundary();
   //readjust X and Y
    x = adjustX(x);
    y = adjustY(y);
}

//for the pause game function
void Ship::stop() {
    timer->stop();
}

void Ship::start() {
    timer->start(32);
}

// reads the window size and adjusts x value based on this
int Ship::adjustX(int x) {
    if (x < 0) {
        return 0;
    } else if (x > maxX) {
        return maxX;
    }
    //nothing was wrong; return default.
    return x;
}

int Ship::adjustY(int y) {
    if (y < 0) {
        return 0;
    } else if (y > maxY) {
        return maxY;
    }
    return y;
}

// moves the ship each time the timer calls it.
//This does nothing for this class currently, see Player
void Ship::nextFrame() {}


