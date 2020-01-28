#ifndef DOGINVADERS_H
#define DOGINVADERS_H

#include "bulletfactory.h"
#include "colorbutton.h"
#include "configreader.h"
#include "shipfactory.h"
#include "sizebutton.h"

#include <QDialog>
#include <QTimer>
#include <QPainter>
#include <QPixmap>
#include <QString>
#include <QPushButton>

//MAGIC NUMBERS
const int HEIGHT = 600;
const int WIDTH = 800;

namespace Ui {
class DogInvaders;
}

class DogInvaders : public QDialog
{
    Q_OBJECT

public:
    explicit DogInvaders(QString fileName, QString filePath, QWidget *parent = 0);
    ~DogInvaders();

protected:
    void paintEvent(QPaintEvent *event);

public slots:
    void nextFrame();
    void pause();

    void displayColorOptions();

    //in future maybe just use a setColor(color) func

    void setRed();
    void setOrange();
    void setYellow();
    void setGreen();
    void setBlue();

    void setTiny();
    void setNormal();
    void setLarge();
    void setGiant();

private:
    void loadFactories();
    void loadTimer();
    void loadButtons();

    void setColor(std::string color);
    void setSizeShip(std::string size);
    //helper functions for pause
    void stopItems();
    void startItems();

    Ui::DogInvaders *ui;

    Ship* player;
    BulletFactory bulletFactory;
    ShipFactory shipFactory;
    ConfigReader reader;
    QPushButton *button;
    bool paused;

    ColorButton *color;
    SizeButton *sizes;



};

#endif // DOGINVADERS_H
