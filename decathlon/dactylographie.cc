#include "dactylographie.hh"

#include <cstdlib>
#include <ctime>

dactylographie::dactylographie()
    :mainwindow(), _flux(fichier()), _decompteMots(10){
    std::srand(std::time(NULL));


    _motADevine = new QLabel("");
    _motADevine->setFixedWidth(150);
    _motEntre = new QLineEdit("");
    _motEntre->setFixedWidth(150);
    std::string tmpString = "appuyez sur entree(pavNum) pour valider il vous reste " + std::to_string(_decompteMots) + " mots";
    _aide = new QLabel(QString::fromStdString(tmpString));
    _aide->setFixedSize(450, 50);

    QVBoxLayout* mainLay = new QVBoxLayout();
    QHBoxLayout* lay = new QHBoxLayout();

    lay->addWidget(_motEntre);
    lay->addWidget(_motADevine);

    mainLay->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
    mainLay->addLayout(lay);
    mainLay->addWidget(_aide);

    setLayout(mainLay);
    initDico();

    _motADevine->setText(QString::fromStdString(motAlea()));
}

void dactylographie::initDico(){
    if(_flux){
          std::string ligne;
          while(std::getline(_flux, ligne)){
              _dico.push_back(ligne);
          }
    }
    else{
        std::cout << "pas de fichier !\n";
    }
}

std::string dactylographie::motAlea(){
    int indice = std::rand()/((RAND_MAX + 1u)/(_dico.size()));
    return _dico.at(indice);
}

void dactylographie::checkMot(){
    if(_decompteMots == 10) _debut = std::chrono::system_clock::now();

    if(_motADevine->text() == _motEntre->text()){

        _motEntre->setStyleSheet("color:black;");
        _motADevine->setText(QString::fromStdString(motAlea()));
        _motEntre->setText("");

        _decompteMots--;
        if(_decompteMots == 0){
            _decompteMots = 10;
            _fin = std::chrono::system_clock::now();
            std::chrono::duration<double> diff = _fin-_debut;
            auto x = std::chrono::duration_cast<std::chrono::milliseconds>(diff);
            emit pb(x.count());
            emit goBackMenu(mode::menu);
        }

    }
    else _motEntre->setStyleSheet("color:red;");
    std::string tmpString = "appuyez sur entree pour valider il vous reste " + std::to_string(_decompteMots) + " mots";
    _aide->setText(QString::fromStdString(tmpString));
}

void dactylographie::keyPressEvent(QKeyEvent *event){
    mainwindow::keyPressEvent(event);
    if(event->key() == Qt::Key_Return) checkMot();
}

