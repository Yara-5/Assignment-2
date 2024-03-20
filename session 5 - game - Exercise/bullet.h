#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsRectItem
{
private:
    int scoreValue;
    QGraphicsTextItem* score;

    Q_OBJECT
public:
    Bullet();

public slots:
    void move();
};

#endif // BULLET_H
