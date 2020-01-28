#ifndef BULLET_H
#define BULLET_H

#include <QPixmap>
#include <QTimer>
#include <QUrl>

#include <list>
#include <string>

//Currently, there is only one type of bullet
class Bullet : public QObject
{
    Q_OBJECT
public:
    Bullet(int speed, int bx, int by,int damage, std::string filename,
            std::list<Bullet*> *inbullets);
    virtual ~Bullet();
    int getX() const;
    int getY() const;
    QPixmap getImage() const;
    void stop();
    void start();

public slots:
    virtual void nextFrame();

protected:
    virtual bool inFrame(int y);
    virtual void setBoundary();
    virtual void deleteSelf();

    int speed; //+ve for player, -ve for enemy
    int bx;
    int by;
    int damage;
    QPixmap bulletImage;
    QTimer *timer;

    int maxHeight;

    std::list<Bullet*> *bullets;
};

#endif // BULLET_H
