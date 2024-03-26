#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int scoreValue;
    QGraphicsTextItem* score;

public:
    Player(QGraphicsTextItem* score=0);
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void createEnemy();



};

#endif // PLAYER_H
