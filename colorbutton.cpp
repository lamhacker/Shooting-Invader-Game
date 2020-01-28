#include "colorbutton.h"
// this class was created to reduce number of lines
//in the main dialog class.

ColorButton::ColorButton(int x, int y, QWidget* parent)
{
    isOpen = false;
    //loads each color
    loadColors(x, y, parent);

}

ColorButton::~ColorButton() {
    delete color;
    delete red;
    delete orange;
    delete yellow;
    delete green;
    delete blue;
}


void ColorButton::loadColors(int x, int y, QWidget* parent) {
    color = new QPushButton("Color", parent);
    color->setVisible(false);
    color->setGeometry(QRect(x, y, 100, 30));
    color->setStyleSheet("background-color: white");
    QObject::connect(color, SIGNAL(released()), parent, SLOT(displayColorOptions()));

    red = new QPushButton("Red", parent);
    red->setVisible(false);
    red->setGeometry(QRect(x, y + 30, 100, 30));
    red->setStyleSheet("background-color: red");
    QObject::connect(red, SIGNAL(released()), parent, SLOT(setRed()));

    orange = new QPushButton("Orange", parent);
    orange->setVisible(false);
    orange->setGeometry(QRect(x, y + (30 * 2), 100, 30));
    orange->setStyleSheet("background-color: orange");
    QObject::connect(orange, SIGNAL(released()), parent, SLOT(setOrange()));

    yellow = new QPushButton("Yellow", parent);
    yellow->setVisible(false);
    yellow->setGeometry(QRect(x, y + (30 * 3), 100, 30));
    yellow->setStyleSheet("background-color: yellow");
    QObject::connect(yellow, SIGNAL(released()), parent, SLOT(setYellow()));

    green = new QPushButton("Green", parent);
    green->setVisible(false);
    green->setGeometry(QRect(x, y + (30 * 4), 100, 30));
    green->setStyleSheet("background-color: green");
    QObject::connect(green, SIGNAL(released()), parent, SLOT(setGreen()));

    blue = new QPushButton("Blue", parent);
    blue->setVisible(false);
    blue->setGeometry(QRect(x, y + (30 * 5), 100, 30));
    blue->setStyleSheet("background-color: blue");
    QObject::connect(blue, SIGNAL(released()), parent, SLOT(setBlue()));

}

//loads main button
void ColorButton::displayMenu(bool pause) {
    color->setVisible(pause);

    //also hide the smaller buttons if it's false
    if (!pause) {
        isOpen = false;
        show(isOpen);
    }
}

void ColorButton::show(bool flag) {
    red->setVisible(flag);
    orange->setVisible(flag);
    yellow->setVisible(flag);
    green->setVisible(flag);
    blue->setVisible(flag);
}

//opens up the color options or closes it
void ColorButton::displayOptions() {
    if (isOpen) {
        isOpen = false;
    } else {
        isOpen = true;
    }

     show(isOpen);
}
