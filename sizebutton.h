#ifndef SIZEBUTTON_H
#define SIZEBUTTON_H

#include <QPushButton>

class SizeButton
{
public:
    SizeButton(int x, int y, QWidget* parent);
    ~SizeButton();

    void displayMenu(bool paused);

private:
    void show(bool show);
    void loadSizes(int x, int y, QWidget* parent);

    QPushButton *tiny;
    QPushButton *normal;
    QPushButton *large;
    QPushButton *giant;
};

#endif // SIZEBUTTON_H
