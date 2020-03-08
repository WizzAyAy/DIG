#pragma once

#include "mainwindow.hh"
#include "mode.hh"

#include <chrono>
#include <fstream>
#include <string>


class menu : public mainwindow
{
    Q_OBJECT
public:
    menu();
    void changePbTot();
    std::string lireWordlRecord();
    void ecrireWordlRecord(int wr);
    std::string fichier(){return "save.sv";}

public slots:
    void goToCliqueGame();
    void goToCliqueTargetGame();
    void goToDactyGame();

    void changePbClique(int newpb);
    void changePbTarget(int newpb);
    void changPbDactyGame(int newpb);

signals:
    void changeMode(mode m);


private:
    QVBoxLayout* _lay;

    QPushButton* _cliqueGame;
    QLabel* _pbCliqueGame;

    QPushButton* _cliqueTarget;
    QLabel* _pbCliqueTarget;

    QPushButton* _dactyGame;
    QLabel* _pbDactyGame;

    QLabel* _total;
    QPushButton* _quitter;

    QLabel* _worldRecord;
    int _pbWordl;
};
