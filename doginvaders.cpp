#include "doginvaders.h"
#include "ui_doginvaders.h"

#include <list>

DogInvaders::DogInvaders(QString fileName, QString filePath, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DogInvaders) {
    //Load the file information
    reader.setup(fileName, filePath);

    ui->setupUi(this);
    this->resize(WIDTH, HEIGHT);

    setStyleSheet("background-color: #000000;");

    loadFactories();
    loadTimer();
    loadButtons();

    paused = false;
}

DogInvaders::~DogInvaders() {
    delete button;
    delete color;
    delete sizes;
    delete ui;
}

/****************** LOAD FUNCTIONS ************************************/
//If we change our design to abstract, we probably don't need this.. ;)
void DogInvaders::loadFactories() {
    //load the factories!
    bulletFactory.set(HEIGHT, WIDTH);
    shipFactory.set(&bulletFactory, HEIGHT, WIDTH);
    //Since there is only currently one ship we can just make one now... for testing?
    player = shipFactory.createShip(reader.getSize(), reader.getColor(), reader.getCoord(), reader.getMove());
}

void DogInvaders::loadTimer() {
    QTimer *timer = new QTimer(this);
          connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
          timer->start(32);
}

void DogInvaders::loadButtons() {
    //pause button is init here instead of its own
    //class because it's always visible.
    button = new QPushButton("Pause", this);
    button->setGeometry(QRect(0, 0, 100, 30));
    button->setStyleSheet("background-color: white");
    connect(button, SIGNAL(clicked()), this, SLOT(pause()));

    //color button...
    color = new ColorButton(100, 0, this);

    //size buttons!
    sizes = new SizeButton(200, 0, this);

}

/********** COLOUR STUFF ***********/
void DogInvaders::displayColorOptions() {
    color->displayOptions();
}

void DogInvaders::setColor(std::string col) {
    //convert to Qstring
    QString color = QString::fromStdString(col);
    player->setColor(color);
    reader.setColor(col);
}

void DogInvaders::setRed() {
   setColor("Red");
}

void DogInvaders::setOrange() {
    setColor("Orange");
}

void DogInvaders::setYellow() {
    setColor("Yellow");
}


void DogInvaders::setGreen() {
    setColor("Green");
}


void DogInvaders::setBlue() {
    setColor("Blue");
}

/*********** SIZE  CHANGES *************/
void DogInvaders::setSizeShip(std::string size)
 {
    QString fix = QString::fromStdString(size);
    player->setSize(fix);
    reader.setSize(size);
}

void DogInvaders::setTiny() {
    setSizeShip("Tiny");
}

void DogInvaders::setNormal() {
    setSizeShip("Normal");
}

void DogInvaders::setLarge() {
    setSizeShip("Large");
}

void DogInvaders::setGiant() {
    setSizeShip("Giant");
}

/********** PAUSED *******************/
//get all the items and pause their timers
void DogInvaders::pause() {
    //if currently not paused, the stop the game
    if (!paused) {
        stopItems();
    } else {
        startItems();
    }

    //show the color menu
    color->displayMenu(paused);
    sizes->displayMenu(paused);
}

void DogInvaders::stopItems() {
    player->stop();

    //draw each bullet
    std::list<Bullet*> bullets = bulletFactory.bullets;
    std::list<Bullet*>::iterator bit = bullets.begin();
    while (bit != bullets.end()) {
        Bullet* current = *bit;
        current->stop();
        bit++;
    }

    paused = true;
    button->setText("Start");
}

void DogInvaders::startItems() {
    player->start();

    std::list<Bullet*> bullets = bulletFactory.bullets;
    std::list<Bullet*>::iterator bit = bullets.begin();
    while (bit != bullets.end()) {
        Bullet* current = *bit;
        current->start();
        bit++;
    }

    paused = false;
    button->setText("Pause");
}


/************* DRAWING OF FRAMES ***********/
//Later on, we could change into Abstract Factory Method.
void DogInvaders::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    //draw each bullet
    std::list<Bullet*> bullets = bulletFactory.bullets;
    std::list<Bullet*>::iterator bit = bullets.begin();
    while (bit != bullets.end()) {
        Bullet* current = *bit;
        painter.drawPixmap(current->getX(), current->getY(), current->getImage());
        bit++;
    }

    //draw player ship
     painter.drawPixmap(player->getX(), player->getY(),player->getImage());

    //in Stage 2, draw the enemies...
}

//actual animations; loads items to redraw
void DogInvaders::nextFrame() {
    update();
}
