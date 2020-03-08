#pragma once
#include <memory>
#include <QObject>
#include <vector>

#include "menu.hh"
#include "clique.hh"
#include "cliquetarget.hh"
#include "dactylographie.hh"
#include "mode.hh"

class engine : public QObject
{
    Q_OBJECT
public:
    engine();
    void start();
    void kill(mode ancien);

public slots:
    void changeMode(mode a);
private:

    mode _mActifs;

    //les differentes fenetres
    menu _menu;
    clique _clique;
    cliquetarget _cliqueTarget;
    dactylographie _dactyGame;
};
