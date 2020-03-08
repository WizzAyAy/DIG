#pragma once

#include "moteur.hh"
#include "window.hh"

#include <QtWidgets>

class traducteur : public QObject{
    Q_OBJECT
public:
    traducteur();
    void showWindow(){ _w.show();}
signals:
    void resultat(int re);
public slots:
    void faireCalcule(std::vector<std::string> attr);
private:
    window _w;
    moteur _m;
};

