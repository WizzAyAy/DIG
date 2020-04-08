#pragma once

#include "game.h"
#include "menu.h"
#include "mode.h"

#include <QObject>


class gestionnaire : public QObject
{

public:
    gestionnaire();
    void changeModeToPlay();
    void changeModeToMenu();

private:
    mode _mode;
    game _game;
    menu _menu;
};
