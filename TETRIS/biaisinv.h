#pragma once

#include "tetrimino.h"

class biaisInv : public tetrimino
{
public:
    biaisInv(size_t li, size_t co);
    std::string getNom() override{return "biaisInv";}
    QColor getColor() override{return Qt::green;}
};
