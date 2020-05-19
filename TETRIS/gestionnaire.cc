#include "gestionnaire.h"

gestionnaire::gestionnaire()
    :QObject(), _game(), _menu(), _endScreen(), _helper(), _database(){
    _mode = mode::inMenu;
    _game.hideGame();
    _helper.hideHelper();
    _endScreen.hideEndScreen();
    _menu.showMenu();
    _music.play();

    connect(_menu.getPlayButton(), &QPushButton::clicked, this, &gestionnaire::changeModeToPlay);
    connect(_menu.getHelperButton(), &QPushButton::clicked, this, &gestionnaire::changeModeToHelper);
    connect(&_game, &game::goBackMenu, this, &gestionnaire::changeModeToMenu);
    connect(&_game, &game::endScreen, this, &gestionnaire::changeModeToEndScreen);
    connect(_helper.getBackButton(), &QPushButton::clicked, this, &gestionnaire::changeModeToMenu);
    connect(_endScreen.getButton(), &QPushButton::clicked, this, &gestionnaire::changeModeToMenu);
    connect(_endScreen.getButton(), &QPushButton::clicked, this, &gestionnaire::insertDataBase);

    connect(&_game, &game::GameOver, &_database, &database::worldRecord);
    connect(&_database, &database::wordlRecordSignal, &_endScreen, &endScreen::updateWordlRecord);


    connect(&_game, &game::nextMusic, this, &gestionnaire::nextMusic);
    connect(&_game, &game::sound, this, &gestionnaire::playSoundSlot);
    connect(&_helper, &helper::playSound, this, &gestionnaire::playSoundSlot);

    connect(&_helper, &helper::newKey, &_game, &game::setKey);
}

void gestionnaire::changeModeToPlay(){
    _mode = mode::inGame;
    _menu.hideMenu();
    _game.restartGame();
    _game.setKey(_helper.getKey());
    _game.randomizeQColorVector();
    playSoundSlot("bip");
}

void gestionnaire::changeModeToMenu(){
    if(_mode == mode::inHelper || _mode == mode::inEndScreen) playSoundSlot("bip");
    _mode = mode::inMenu;
    _game.hideGame();
    _helper.hideHelper();
    _endScreen.hideEndScreen();
    _menu.randomizeQColorVector();
    _menu.update();
    _menu.showMenu();
}

void gestionnaire::changeModeToHelper(){
    _mode = mode::inHelper;
    _menu.hideMenu();
    _helper.randomizeQColorVector();
    _helper.update();
    _helper.showHelper();
    playSoundSlot("bip");
}

void gestionnaire::changeModeToEndScreen(){
    _mode = mode::inEndScreen;
    _game.hideGame();
    _endScreen.randomizeQColorVector();
    _endScreen.update();
    _endScreen.showEndScreen();
    playSoundSlot("clap");
}

void gestionnaire::playSoundSlot(std::string name){
    _music.playSound(name);
}

void gestionnaire::nextMusic(){
    _music.nextMusic();
}

void gestionnaire::insertDataBase(){
    _database.insertBase(_endScreen.getLineEdit(), _game.getScore());
}
