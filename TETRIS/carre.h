#pragma once

#include "tetrimino.h"

class carre : public tetrimino
{
public:
    carre(size_t li, size_t co);
    std::string getNom() override{return "carre";}
    QColor getColor() override{return Qt::yellow;}
};

