
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include <QGraphicsTextItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // *******  Create the View ********


    QGraphicsView view;
    view.setFixedSize(800,600);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);




    // ******* Create the Scene ********
    QGraphicsScene scene;
    scene.setSceneRect(0,0,800,600);


    //Setting brushes
    QBrush redBrush(Qt::red);

    // *******  Create the Player ********
    QPixmap pixmap1 ("C:/Users/habib/Downloads/ship.png");
    pixmap1=pixmap1.scaledToWidth(100);
    pixmap1=pixmap1.scaledToHeight(100);

    Player *player = new Player;
    player->setPixmap(pixmap1);
    player->setPos(350,500);
    scene.addItem(player);

    // *******  Setting the foucs to the Player ********
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // *******  Adjust the location of the Player (middle of the screen) ********


   // *******   Assign scene to the view   ***************
    view.setScene(&scene);


    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time->start(2000);

    //QGraphicsTextItem* score =new QGraphicsTextItem;
    //score->setFont(QFont("times",16));
   // score->setPlainText("Score: " +QString::number(0));
    //score->setPos(500,10);
    //scene.addItem(score);
     //view.show();

    return a.exec();


}
