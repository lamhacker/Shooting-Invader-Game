#include "doginvaders.h"

#include <QApplication>
#include <QString>

#include <iostream>


using namespace std;
int main(int argc, char *argv[])
{
    //filepaths
    QString fileName("config.txt");
    QString filePath("../DogInvader/");

    QApplication a(argc, argv);

    DogInvaders w(fileName, filePath);
    w.show();

    //stops people resizing the window
    w.setFixedSize(w.size());
    return a.exec();
}
