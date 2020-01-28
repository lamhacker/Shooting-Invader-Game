#ifndef COLORBUTTONS_H
#define COLORBUTTONS_H

#include <QPushButton>

class ColorButton
{
public:
    ColorButton(int x, int y, QWidget* parent);
    ~ColorButton();

    void displayMenu(bool paused);
    void displayOptions();
private:
    void loadColors(int x, int y, QWidget* parent);
    void show(bool flag);
    bool isOpen;
    QPushButton *color;

    QPushButton *red;
    QPushButton *orange;
    QPushButton *yellow;
    QPushButton *green;
    QPushButton *blue;
};

#endif // COLORBUTTONS_H
