#include "cliquetarget.hh"
#include "mode.hh"

#include <cstdlib>
#include <ctime>
#include <iostream>

cliquetarget::cliquetarget()
    :mainwindow(), _countTarget(0){
    std::srand(std::time(NULL));

    std::vector<int> tmpRand;
    for(int i = 0; i < 15; i++){
        tmpRand.push_back(30 + std::rand()/((RAND_MAX + 1u)/(width()-80)));
        tmpRand.push_back(30 + std::rand()/((RAND_MAX + 1u)/(height()-80)));
    }

    int j = 0;
    for(int i = 0; i < 15; i++){

        _lesTargets.push_back(new target(i+1, this));
        std::srand(std::time(nullptr));
        if(tmpRand.at(i) % 3 == 0) _lesTargets.at(i)->setStyleSheet("background-color:blue;");
        else if(tmpRand.at(i) % 3 == 1) _lesTargets.at(i)->setStyleSheet("background-color:red;");
        else _lesTargets.at(i)->setStyleSheet("background-color:green;");

        _lesTargets.at(i)->move(tmpRand.at(j),tmpRand.at(j+1));
        j += 2;

        _lesTargets.at(i)->setEnabled(false);
        _lesTargets.at(i)->setVisible(false);
        QObject::connect(_lesTargets.at(i), &target::next, this, &cliquetarget::goNext);
    }
    _lesTargets.at(0)->setVisible(true);
    _lesTargets.at(0)->setEnabled(true);
    QObject::connect(_lesTargets.back(), &target::last, this, &cliquetarget::goLast);
}

void cliquetarget::goNext(){
    if(_countTarget == 0) _debut = std::chrono::system_clock::now();
    _lesTargets.at(_countTarget)->setEnabled(false);
    _lesTargets.at(_countTarget)->setVisible(false);
    _countTarget++;
    _lesTargets.at(_countTarget)->setEnabled(true);
    _lesTargets.at(_countTarget)->setVisible(true);

}

void cliquetarget::goLast(){
    emit goBackMenu(mode::menu);
    _fin = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = _fin-_debut;
    auto x = std::chrono::duration_cast<std::chrono::milliseconds>(diff);
    emit pb(x.count());
    _lesTargets.at(0)->setVisible(true);
    _lesTargets.at(0)->setEnabled(true);
    _countTarget = 0;
}



