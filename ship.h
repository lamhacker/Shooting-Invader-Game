#ifndef SHIP_H
#define SHIP_H

#include "bulletfactory.h"

#include <QBitmap>
#include <QObject>
#include <QPixmap>
#include <QString>
#include <QTimer>

#include <string>

class Ship : public QObject
{
    Q_OBJECT
public:
    Ship(std::string size, std::string color, int coord, std::string filename, BulletFactory* bulletFactory, int height, int width);
    virtual ~Ship() {}

    /************* GETTERS *********************/
    int getX() const;
    int getY() const;
    QPixmap getImage() const;

    /************ other ***********************/
    void stop();
    void start();

    void setColor(QString color);
    void setSize(QString size);

    static QString fileType;
public slots:
    virtual void nextFrame();

protected:
    int adjustX(int x);
    int adjustY(int y);
    void setBoundary();

    /************ VARIABLES ********************/
    QTimer *timer;
    QPixmap shipImage;
    QString path; //original image path

    QString size;
    QString color;
    int coord; //store the initial coord for future levels!
    int x; // for current level use
    int y;

    //max X and Y coordinate for this ship
    int maxX; //QP will draw from topleft corner so min is just 0.
    int maxY;

    int cWidth; //canvase dimensions.
    int cHeight; //needs to save this for recalc.

    //misc
    BulletFactory* bulletFactory;

};
#endif // SHIP_H
