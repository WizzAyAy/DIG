#include "engine.hh"
#include "mode.hh"

#include <memory>

engine::engine()
{
    start();

    connect(&_menu, &menu::changeMode, this, &engine::changeMode);

    connect(&_clique, &mainwindow::goBackMenu, this, &engine::changeMode);
    connect(&_cliqueTarget, &mainwindow::goBackMenu, this, &engine::changeMode);
    connect(&_dactyGame, &mainwindow::goBackMenu, this, &engine::changeMode);

    connect(&_clique, &mainwindow::pb, &_menu, &menu::changePbClique);
    connect(&_cliqueTarget, &mainwindow::pb, &_menu, &menu::changePbTarget);
    connect(&_dactyGame, &mainwindow::pb, &_menu, &menu::changPbDactyGame);
}

void engine::start(){
    _mActifs = mode::menu;
    _menu.setVisible(true);
    _menu.setEnabled(true);
}

void engine::kill(mode ancien){
    if(ancien == mode::menu){
        _menu.setVisible(false);
        _menu.setEnabled(false);
    }
    if(ancien == mode::clique){
        _clique.setVisible(false);
        _clique.setEnabled(false);
    }
    if(ancien == mode::cliqueTarget){
        _cliqueTarget.setVisible(false);
        _cliqueTarget.setEnabled(false);
    }
    if(ancien == mode::dactyGame){
        _dactyGame.setVisible(false);
        _dactyGame.setEnabled(false);
    }
}

void engine::changeMode(mode a){
    if(a == mode::menu){
        kill(_mActifs);
        _menu.setVisible(true);
        _menu.setEnabled(true);
    }
    else if(a == mode::clique){
        kill(_mActifs);
        _clique.setVisible(true);
        _clique.setEnabled(true);
    }
    else if(a == mode::cliqueTarget){
        kill(_mActifs);
        _cliqueTarget.setVisible(true);
        _cliqueTarget.setEnabled(true);
    }
    else if(a == mode::dactyGame){
        kill(_mActifs);
        _dactyGame.setVisible(true);
        _dactyGame.setEnabled(true);
    }

    _mActifs = a;

}
