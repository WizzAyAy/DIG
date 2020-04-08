#include "gestionnaire.h"

gestionnaire::gestionnaire()
    :QObject(), _game(), _menu(){
    _mode = mode::inMenu;
    _game.hideGame();

    _menu.showMenu();
    connect(_menu.getPlayButton(), &QPushButton::clicked, this, &gestionnaire::changeModeToPlay);
    connect(&_game, &game::goBackMenu, this, &gestionnaire::changeModeToMenu);
}

void gestionnaire::changeModeToPlay(){
    _mode = mode::inGame;
    _menu.hideMenu();
    _game.restartGame();

}

void gestionnaire::changeModeToMenu(){
    _mode = mode::inMenu;
    _game.hideGame();
    _menu.showMenu();
}
