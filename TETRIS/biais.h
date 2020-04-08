#pragma once

#include "tetrimino.h"

class biais : public tetrimino
{
public:
    biais(size_t li, size_t co);
    std::string getNom() override{return "biais";}
    QColor getColor() override{return Qt::red;}
};
