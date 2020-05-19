#pragma once

#include "game.h"
#include "menu.h"
#include "mode.h"
#include "music.h"
#include "helper.h"
#include "endscreen.h"
#include "database.h"

#include <QObject>
#include <string>

/*
 *  classe qui fait le pont entre toutes les fenetre
*/

class gestionnaire : public QObject
{

public:
    gestionnaire();
    //change le mode en ...
    void changeModeToPlay();
    void changeModeToMenu();
    void changeModeToHelper();
    void changeModeToEndScreen();
public slots:
    //permet de jouer une musique de la class music
    void playSoundSlot(std::string name);
    //passe a la musique suivante
    void nextMusic();
    //insert dans la database le nom du end screen et le score courrant
    void insertDataBase();

private:
    mode _mode;
    game _game;
    menu _menu;
    endScreen _endScreen;
    helper _helper;
    music _music;
    database _database;
};
