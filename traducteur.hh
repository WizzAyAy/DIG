#pragma once

#include "calc.h"
#include "window.hh"

#include <QtWidgets>

class traducteur : public QObject
{
    Q_OBJECT
public:
    traducteur();
    void redirige(QString s);
    void show(){w.show();}
signals:
    void res(double a);
    void pushcal(QString s);
    void pushope(QString s);
private:
    window w;
    Calc c;
};
