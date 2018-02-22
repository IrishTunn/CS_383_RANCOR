#include "BTcharacter.h"
#include "JTwalls.h"
#include "KNSkillManager.h"

#include <iostream>
#include <QPoint>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

/*
//No real reason why to have this intermediate constructor, just assume the value is 0 if not given.
Character::Character(QWidget *parent)
    : QWidget(parent)
{
    //tick = new QTimer(this);
    Character( parent, 0 );
}
*/

Character::Character( int characterNumber )
{
    int length = 100;

    //player = new QGraphicsRectItem();
    setRect( 0, 0, length, length );
    //player->setPos( (scene()->width() - length)/2 , (scene()->height() - length)/2 );
    setPos( 400, 300 );

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocusPolicy(Qt::StrongFocus);
    QGraphicsRectItem::setFocus();

    //Get Walls Object
    //https://stackoverflow.com/questions/23533691/qt-collision-detection-with-custom-qgraphicsitem-classes
    QList<QGraphicsItem *> list = collidingItems() ;

    foreach(QGraphicsItem * i , list)
    {
        Walls * item= dynamic_cast<Walls *>(i);
        if (item)
        {
            walls = item;
            break;
        }
    }

    skills = new SkillManager( this, characterNumber );
    if (walls == NULL) {
        walls = new QGraphicsRectItem();
        walls->setRect(0,0,720,520);
        walls->setPos(40,40);
    }
}

Character::~Character()
{
    //delete(player);
    //player = NULL;
    delete(skills);
    skills = NULL;
}

void Character::setSpeed(int newSpeed)
{
    if (speed >= 0) speed = newSpeed;
}

QPoint Character::getPosition()
{
    return QPoint( QGraphicsRectItem::x() + (QGraphicsRectItem::rect().width()/ 2) , QGraphicsRectItem::y() + (QGraphicsRectItem::rect().height()/2) );
}

void Character::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        qDebug() << "Pressing up.";
        moveUp = true;
    } else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        qDebug() << "Pressing down.";
        moveDown = true;
    } else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        qDebug() << "Pressing right.";
        moveRight = true;
    } else if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        qDebug() << "Pressing left.";
        moveLeft = true;
    }
}

void Character::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W) {
        qDebug() << "Releasing up.";
        moveUp = false;
    } else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S) {
        qDebug() << "Releasing down.";
        moveDown = false;
    } else if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D) {
        qDebug() << "Releasing right.";
        moveRight = false;
    } else if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A) {
        qDebug() << "Releasing left.";
        moveLeft = false;
    }
}

void Character::move()
{
    double moveDistance = speed * 1;

    /* Alternate way that movement can be controlled, uses collisions to ensure that
     * the player always stays within the bounding rectangle object that is created by the
     * Map class. Not sure if i need to include the Map class to ensure that i will be able
     * to detect the object that is colliding with the player.
     */
    /*
    {
        QGraphicsRectItem * ghost = new QGraphicsRectItem();
        ghost->setRect( player->rect() );
        if (moveUp) {
            ghost->setPos( ghost->x(), ghost->y() - moveDistance );
            QList<QGraphicsItem *> collidingItems = collidingItems(ghost,  )
            if () {

            }
        }
        if (moveDown) {
            player->setPos( ghost->x(), ghost->y()+moveDistance );
            if () { //if past border

            }
        }
        if (moveRight) {
            player->setPos( ghost->x()+moveDistance, ghost->y() );
            if () { //if past border

            }
        }
        if (moveLeft) {
            player->setPos( ghost->x()-moveDistance, ghost->y() );
            if () { //if past border

            }
        }
    }
    */
//If the above method has issues, just use this one.
    int x = QGraphicsRectItem::pos().x();  //Current x and y values, before moving player.
    int y = QGraphicsRectItem::pos().y();
    if (moveUp) {
        int newY = QGraphicsRectItem::pos().y() - moveDistance;
        int topWall = walls->pos().y();
        if (newY >= topWall) {  //If not colliding with walls
            setPos( x , newY );
        } else {                //Move to wall edge instead.
            setPos( x , topWall );
        }
    }
    if (moveDown) {
        int newY = QGraphicsRectItem::pos().y()  + moveDistance;
        int botWall = QGraphicsRectItem::pos().y() + QGraphicsRectItem::rect().height();
        if (botWall >= newY + QGraphicsRectItem::rect().height()){    //If not colliding with walls
            setPos( x, newY );
        } else {              //move to wall edge instead.
            setPos( x, botWall - QGraphicsRectItem::rect().height());
        }
    }
    if (moveRight) {
        int newX = QGraphicsRectItem::pos().x()  + moveDistance;
        int rightWall = walls->pos().x() + walls->rect().width();
        if (newX + QGraphicsRectItem::rect().width() <= rightWall){ //If not colliding with walls
            setPos( newX, y );
        } else {                //move to wall edge intead
            setPos( rightWall - QGraphicsRectItem::rect().width(), y ); //move to wall's edge.
        }
    }
    if (moveLeft) { //if not moving past border
        int newX = QGraphicsRectItem::pos().x() - moveDistance;
        int leftWall = QGraphicsRectItem::pos().x();
        if (leftWall <= newX) { //If not colliding with walls
            setPos( newX, y );
        } else {                 //move to wall edge instead
            setPos( leftWall , y );
        }
    }
}
