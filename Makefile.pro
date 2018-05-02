######################################################################
# Automatically generated by qmake (3.1) Wed Feb 21 10:40:59 2018
######################################################################
QT += core gui      \
      multimedia
      #multiwidgets  \
      #winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets 


TEMPLATE = app
TARGET = SpaceShooter
INCLUDEPATH += . inc inc/Jake inc/James inc/Nick inc/Baylus inc/Angelo inc/Karstin
FORMS += inc/mainmenu.ui \
    inc/victoryscreen.ui
# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += inc/JAaudio.h inc/JAgame.h  inc/Jake/sound.h inc/Jake/music.h                        \
           inc/JTmap.h inc/James/JTdoor.h inc/James/JTroom.h inc/James/JTwalls.h inc/James/JTgoal.h inc/James/JTbackground.h inc/James/JTCollidable.h inc/James/JTgenerator.h\
           inc/NAenemyupdater.h inc/Nick/enemy.h                \
           inc/KNSkillManager.h inc/Karstin/KNClassType.h inc/Karstin/KNClassTypeDatabase.h inc/Karstin/KNSkill.h inc/Karstin/KNItem.h inc/Karstin/KNItemDatabase.h inc/Karstin/KNPermaMod.h inc/Karstin/KNWeapon.h   \
           inc/Angelo/ASmenu.h                                  \
           inc/BTcharacter.h inc/Baylus/BTplayer.h inc/Baylus/BTshot.h \
    inc/Nick/enemyspawner.h \
    inc/Baylus/autopilot.h \
    inc/Jake/JAaudiosuper.h \
    inc/Angelo/ASVictoryScreen.h \
    inc/BTentity.h \
    inc/Nick/rangedenemy.h \
    inc/Nick/meleeenemy.h \
    inc/BTenemyShot.h \
    inc/BTplayerShot.h




SOURCES +=                                                            \
src/Jake/JAaudio.cpp src/Jake/JAgame.cpp src/Jake/main.cpp            \
src/James/JTmap.cpp src/James/JTwalls.cpp src/James/JTroom.cpp src/James/JTdoor.cpp src/James/JTgoal.cpp src/James/JTbackground.cpp src/James/JTcollidable.cpp src/James/JTgenerator.cpp\
src/Nick/enemy.cpp src/Nick/enemyupdater.cpp                          \
src/Karstin/KNSkillManager.cpp src/Karstin/KNClassType.cpp src/Karstin/KNClassTypeDatabase.cpp src/Karstin/KNSkill.cpp src/Karstin/KNItem.cpp src/Karstin/KNItemDatabase.cpp src/Karstin/KNPermaMod.cpp src/Karstin/KNWeapon.cpp  \
src/Angelo/ASmenu.cpp                                                 \
src/Baylus/BTcharacter.cpp src/Baylus/BTplayer.cpp src/Baylus/BTshot.cpp \
    src/Nick/enemyspawner.cpp \
    src/Baylus/autopilot.cpp \
    src/Angelo/ASVictoryScreen.cpp \
    src/Baylus/BTentity.cpp \
    src/Jake/JAmusic.cpp \
    src/Jake/JAsound.cpp \
    src/Nick/rangedenemy.cpp \
    src/Nick/meleeenemy.cpp \
    src/Baylus/BTenemyShot.cpp \
    src/Baylus/BTplayerShot.cpp \
    src/Jake/JAaudiosuper.cpp



RESOURCES += src/Jake/sounds.qrc \
    src/James/JTimages.qrc    \
    src/Baylus/BTimages.qrc \
    src/Nick/NAresources.qrc
