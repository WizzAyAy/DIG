#pragma once
#include "mainwindow.hh"
#include "target.hh"

#include <vector>
#include <chrono>

class cliquetarget : public mainwindow
{
    Q_OBJECT
public:
    cliquetarget();
public slots:
    void goNext();
    void goLast();
private:
    std::vector<target*> _lesTargets;
    int _countTarget;

    std::chrono::time_point<std::chrono::system_clock> _debut;
    std::chrono::time_point<std::chrono::system_clock> _fin;
};

