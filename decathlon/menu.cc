#include <iostream>

#include "menu.hh"
#include "mode.hh"

menu::menu()
    :mainwindow(), _pbWordl(std::stoi(lireWordlRecord())){

    //inti lay
    _lay = new QVBoxLayout();
    setLayout(_lay);

    //inti widget
    _cliqueGame = new QPushButton("cliqueGame");
    _pbCliqueGame = new QLabel("pas encore de pb");

    _cliqueTarget = new QPushButton("cliqueTargetGame");
    _pbCliqueTarget = new QLabel("pas encore de pb");

    _dactyGame = new QPushButton("dactyGame");
    _pbDactyGame = new QLabel("pas encore de pb");

    _total = new QLabel("termine tous les jeux pour avoir un pb total !");
    _quitter = new QPushButton("quitter");

    _worldRecord = new QLabel();
    _worldRecord->setText("Wr : " + QString::fromStdString(lireWordlRecord()) + "ms");

    //placement
    QHBoxLayout* layClique = new QHBoxLayout();
    layClique->addWidget(_cliqueGame);
    layClique->addWidget(_pbCliqueGame);
    _lay->addLayout(layClique);

    QHBoxLayout* layTarget = new QHBoxLayout();
    layTarget->addWidget(_cliqueTarget);
    layTarget->addWidget(_pbCliqueTarget);
    _lay->addLayout(layTarget);

    QHBoxLayout* lay = new QHBoxLayout();
    lay->addWidget(_dactyGame);
    lay->addWidget(_pbDactyGame);
    _lay->addLayout(lay);

    _lay->addWidget(_total);
    _lay->addWidget(_quitter);
    _lay->addWidget(_worldRecord);

    _lay->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);


    //Connect
    QObject::connect(_quitter, &QPushButton::clicked, this, &menu::close);
    QObject::connect(_cliqueGame, &QPushButton::clicked, this, &menu::goToCliqueGame);
    QObject::connect(_cliqueTarget, &QPushButton::clicked, this, &menu::goToCliqueTargetGame);
    QObject::connect(_dactyGame, &QPushButton::clicked, this, &menu::goToDactyGame);
}


void menu::goToCliqueGame(){
    emit changeMode(mode::clique);
}

void menu::goToCliqueTargetGame(){
    emit changeMode(mode::cliqueTarget);
}

void menu::goToDactyGame(){
    emit changeMode(mode::dactyGame);
}

void menu::changePbClique(int newpb){
    if(newpb < _pbCliqueGame->text().toInt() || _pbCliqueGame->text() == "pas encore de pb"){
        _pbCliqueGame->setText(QString::fromStdString(std::to_string(newpb)));
        _pbCliqueGame->setText(_pbCliqueGame->text());
    }
    changePbTot();
}

void menu::changePbTarget(int newpb){
    if(newpb < _pbCliqueTarget->text().toInt() || _pbCliqueTarget->text() == "pas encore de pb"){
        _pbCliqueTarget->setText(QString::fromStdString(std::to_string(newpb)));
        _pbCliqueTarget->setText(_pbCliqueTarget->text());
    }
   changePbTot();
}

void menu::changPbDactyGame(int newpb){
    if(newpb < _pbDactyGame->text().toInt() || _pbDactyGame->text() == "pas encore de pb"){
        _pbDactyGame->setText(QString::fromStdString(std::to_string(newpb)));
        _pbDactyGame->setText(_pbDactyGame->text());
    }
    changePbTot();
}

std::string menu::lireWordlRecord(){
    std::ifstream lire(fichier());
    if(lire){
          std::string record;
          lire >> record;
          return record;
    }
    else{
        throw ("pas de fichier");
        return "marcher pas";
    }
}

void menu::ecrireWordlRecord(int wr){
    std::ofstream ecrire(fichier());
    if(ecrire){
        ecrire << wr;
    }
    else{
        throw ("pas de fichier");
    }
}


void menu::changePbTot(){
    if(_pbCliqueGame->text() != "pas encore de pb"
    && _pbCliqueTarget->text() != "pas encore de pb"
    && _pbDactyGame->text() != "pas encore de pb"){

        _total->setText(QString::fromStdString(std::to_string(
        _pbCliqueGame->text().toInt() + _pbCliqueTarget->text().toInt() + _pbDactyGame->text().toInt())));
        _total->setText("total pb : " + _total->text() + "ms");

        int tmp = _pbCliqueGame->text().toInt() + _pbCliqueTarget->text().toInt() + _pbDactyGame->text().toInt();
        if (tmp < _pbWordl){
            _pbWordl = tmp;
            ecrireWordlRecord(_pbWordl);
            _worldRecord->setText(QString::fromStdString(lireWordlRecord()) + "ms");
        }
    }
}
