#include "music.h"

music::music()
    :QMediaPlayer(){

    _playList = new QMediaPlaylist();
    initSound();
    initPlayList();
}

void music::initPlayList(){
    _playList->addMedia(QUrl::fromLocalFile("./res/music/theme_8bits.mp3"));
    _playList->addMedia(QUrl::fromLocalFile("./res/music/theme_99.mp3"));
    _playList->addMedia(QUrl::fromLocalFile("./res/music/theme_acapella.mp3"));
    _playList->addMedia(QUrl::fromLocalFile("./res/music/theme_acordeon.mp3"));
    _playList->addMedia(QUrl::fromLocalFile("./res/music/theme_batterie.mp3"));
    _playList->addMedia(QUrl::fromLocalFile("./res/music/theme_dubstep.mp3"));
    _playList->addMedia(QUrl::fromLocalFile("./res/music/theme_hardcore.mp3"));
    _playList->addMedia(QUrl::fromLocalFile("./res/music/theme_hardstyle.mp3"));
    _playList->addMedia(QUrl::fromLocalFile("./res/music/theme_metal.mp3"));
    _playList->addMedia(QUrl::fromLocalFile("./res/music/theme_nightcore.mp3"));
    _playList->addMedia(QUrl::fromLocalFile("./res/music/theme_thec.mp3"));
    _playList->addMedia(QUrl::fromLocalFile("./res/music/theme_trap.mp3"));

    _playList->shuffle();
    _playList->setCurrentIndex(1);

    setPlaylist(_playList);
    setVolume(25);
}

void music::initSound(){
    _sounds.push_back({new QSound("./res/sons/bip.wav"), "bip"});
    _sounds.push_back({new QSound("./res/sons/powerUp.wav"), "powerUp"});
    _sounds.push_back({new QSound("./res/sons/LevelUp.wav"), "levelUp"});
    _sounds.push_back({new QSound("./res/sons/SpecialLineClearSingle.wav"), "1line"});
    _sounds.push_back({new QSound("./res/sons/SpecialLineClearDouble.wav"), "2line"});
    _sounds.push_back({new QSound("./res/sons/SpecialLineClearTriple.wav"), "3line"});
    _sounds.push_back({new QSound("./res/sons/SpecialTetris.wav"), "tetris"});
    _sounds.push_back({new QSound("./res/sons/noMoney.wav"), "noMoney"});
    _sounds.push_back({new QSound("./res/sons/hardDrop.wav"), "hardDrop"});
    _sounds.push_back({new QSound("./res/sons/move.wav"), "move"});
    _sounds.push_back({new QSound("./res/sons/moveFail.wav"), "moveFail"});
    _sounds.push_back({new QSound("./res/sons/hold.wav"), "hold"});
    _sounds.push_back({new QSound("./res/sons/gameOver.wav"), "gameOver"});
    _sounds.push_back({new QSound("./res/sons/gameStart.wav"), "gameStart"});
    _sounds.push_back({new QSound("./res/sons/ok.wav"), "ok"});
    _sounds.push_back({new QSound("./res/sons/not.wav"), "not"});
    _sounds.push_back({new QSound("./res/sons/explosion.wav"), "explosion"});
    _sounds.push_back({new QSound("./res/sons/coin.wav"), "coin"});
    _sounds.push_back({new QSound("./res/sons/wrong.wav"), "wrong"});
    _sounds.push_back({new QSound("./res/sons/clap.wav"), "clap"});
}

void music::nextMusic(){
    _playList->next();
}

void music::playSound(const std::string &name){
    for(auto x : _sounds){
        if(x.soundName == name){
            x.sound->play();
            return;
        }
    }
}
