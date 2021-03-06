/*
 * BTshot.cpp
 * Baylus Tunnicliff    3/3/2018
 * Team Rancor      Space Shooter X
 * Shot Class Implementation
 *
 *
 *
 *
 */



#include "BTshot.h"
#include "BTplayer.h"
#include "NAenemyupdater.h"
#include "JTwalls.h"

#include <QLineF>
//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <cmath>
#include <ctgmath>

#define PI 3.14159265358979323846264



struct weaponStats* Shot::sWeapon;

Shot::Shot( double s, QLineF l)
    //:QGraphicsRectItem(l.x1(), l.y1(), size, size)
{
    qDebug() << "Shooting.";
    /*
    if (!sWeapon) { //If weapon variable has not been initialized.
        //Replace this with setting the weapon to the passed in weapon stats.
        sWeapon = new (struct weaponStats);
    }
    if (!(sWeapon->myPixMap))   //if weapon pixmap doesnt exist.
        sWeapon->myPixMap = new QPixmap(":/images/Graphics/Lasers/laserGreen04.png");
    //Draw Graphics
    setPixmap(*(sWeapon->myPixMap));
    */
    setPixmap(QPixmap(":/images/Graphics/Lasers/laserGreen04.png"));

    //parentType = p;

    //this->pixmap().rect().center();
    shotSpeed = s;
    line = l;
    //angle = l.angleTo(QLineF( 0.0,0.0,1.0, 0.0 ));
    //angle = l.angle();
    setRotation( 90-l.angle());
    //qDebug() << "Angle" << 90-l.angle();
    angle = (l.angle() * PI ) / 180;
    //QGraphicsRectItem::setRect( 0, 0, size, size );
    //QGraphicsRectItem::setPos( l.x1(), l.y1() );
    setPos( l.x1(), l.y1() );
    //myCharacter = c;
}

Shot::~Shot()
{
    //delete(this);
//qDebug() << "Shot death." << pos();
}

/*  mapToSpread()
 *
 *
 *
 */
double Shot::mapToSpread(double x, double spread, double inputStart, double inputEnd)
{
    //          static bool first = true;
    //https://stackoverflow.com/questions/5731863/mapping-a-numeric-range-onto-another
    //slope = 1.0 * (output_end - output_start) / (input_end - input_start)
    static double slope = 1.0 * (spread * 2) / (inputEnd - inputStart);
    return ( (slope * (x - inputStart)) - spread );
}


/* update()
 * Moves shot according to shotSpeed,
 * Checks for collisions with enemies and
 * Wall objects.
 */
int Shot::shotUpdate()
{
    //Move shot.
    double newX = x() + ( shotSpeed * cos(angle));
    double newY = y() - ( shotSpeed * sin(angle));
   //see header for details for why this ^ signage

    setPos( newX, newY );

    //Check collisions.
    //For fixing the small annoyances with destroying the shots earlier than
    //When they are completely outside the walls
        //Try using "QPainterPath::intersects(const QRectF &rectangle) const"
/*
http://doc.qt.io/qt-5/qtwidgets-graphicsview-diagramscene-arrow-cpp.html
    method "paint()" uses several methods of obtaining the intersecting items.
*/
    /*
    QList<QGraphicsItem *> list = collidingItems(Qt::IntersectsItemShape) ;
    bool die = false;
    bool walls = false;
    foreach(QGraphicsItem * i , list)
    {
        Enemy * item= dynamic_cast<Enemy *>(i);
        if (item) { //If enemy has been hit.
            //Signal enemy Damage,
            if ( typeid(parentType) != typeid(Enemy) ) {
                //If this shot was not from an enemy.

                //Remove Shot.
                //delete this;    //Note: Scary stuff to do this, handle with extreme care.
                item->attacked(damage);
                die = true;
            } else {
                //If the shot was from and enemy, dont damage enemies.
            }

        }
        Walls* wall = dynamic_cast<Walls *>(i);
        if (wall) {
            walls = true;
        }

        Player* p = dynamic_cast<Player *>(i);
        if ( p ) {  //If the shot is hitting the (a(?)) player.
            if ( typeid(parentType) != typeid(Player) ) {
                //The shot was not from the player.

                //Deal damage to the player.
                p->dealDamageToPlayer(parentType.getAtkValue());
                die = true; //Shot dies after checking collisions.
            }   //If the shot is from a player, dont damage player.


        }
    }* /
    if (die || !walls) {
        //qDebug() << "Hit Something!";
        delete this;
    }*/

    if (checkCollisions()) {
        qDebug() << "Shot dying.";
        delete this;
    }

    return 0;
}

/* This slot is initialized by calling function
 * It is used so that a single signal can be
 * connected to the shots to tell them to die,
 * that way control over them does not require
 * the pointer to the object.
 *
 */
void Shot::kill()
{
    delete this;
}


