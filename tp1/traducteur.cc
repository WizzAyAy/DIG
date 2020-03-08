#include "traducteur.hh"
#include <iostream>

traducteur::traducteur()
    :_w(), _m()
{
    QObject::connect(_w.getButton(), &QPushButton::clicked, &_w, &window::onclickEgal);
    QObject::connect(&_w, &window::signalWindow, this, &traducteur::faireCalcule);
    QObject::connect(this, &traducteur::resultat, &_w, &window::changeRes);
}

void traducteur::faireCalcule(std::vector<std::string> attr)
{
    emit resultat (_m.calcul(attr));  
}
