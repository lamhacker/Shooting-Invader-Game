#include "sizebutton.h"

SizeButton::SizeButton(int x, int y, QWidget* parent)
{
    loadSizes(x, y, parent);

}

SizeButton::~SizeButton() {
    delete tiny;
    delete normal;
    delete large;
    delete giant;
}


//loads the buttons... currently all hardcoded.
//but theyre buttons so it's fine.
void SizeButton::loadSizes(int x, int y, QWidget* parent) {
    tiny = new QPushButton("Tiny", parent);
    tiny->setVisible(false);
    tiny->setGeometry(QRect(x + 100, y, 100, 30));
    tiny->setStyleSheet("background-color: white");
    QObject::connect(tiny, SIGNAL(released()), parent, SLOT(setTiny()));

    normal = new QPushButton("Normal", parent);
    normal->setVisible(false);
    normal->setGeometry(QRect(x + (100 * 2), y, 100, 30));
    normal->setStyleSheet("background-color: white");
    QObject::connect(normal, SIGNAL(released()), parent, SLOT(setNormal()));

    large = new QPushButton("Large", parent);
    large->setVisible(false);
    large->setGeometry(QRect(x + (100 * 3), y, 100, 30));
    large->setStyleSheet("background-color: white");
    QObject::connect(large, SIGNAL(released()), parent, SLOT(setLarge()));

    giant = new QPushButton("Giant", parent);
    giant->setVisible(false);
    giant->setGeometry(QRect(x + (100 * 4), y, 100, 30));
    giant->setStyleSheet("background-color: white");
    QObject::connect(giant, SIGNAL(released()), parent, SLOT(setGiant()));
}


void SizeButton::show(bool show) {
    tiny->setVisible(show);
    normal->setVisible(show);
    large->setVisible(show);
    giant->setVisible(show);
}

void SizeButton::displayMenu(bool paused) {
    if (paused) {
        //if game is paused, hide them
        show(paused);
    } else {
        //else show them
        show(paused);
    }

}
