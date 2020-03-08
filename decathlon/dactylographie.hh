#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

#include "mainwindow.hh"

class dactylographie : public mainwindow
{
    Q_OBJECT
public:
    dactylographie();

    std::string fichier(){return "list_mot_en.txt";}
    void initDico();
    std::string motAlea();

public slots:
    void checkMot();
    void keyPressEvent(QKeyEvent *event);
private:
    std::ifstream _flux;

    QLabel* _motADevine;
    QLabel* _aide;
    QLineEdit* _motEntre;
    int _decompteMots;

    std::vector<std::string> _dico;

    std::chrono::time_point<std::chrono::system_clock> _debut;
    std::chrono::time_point<std::chrono::system_clock> _fin;
};
