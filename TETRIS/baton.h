#pragma once

#include "tetrimino.h"

class baton : public tetrimino
{
public:
    baton(size_t li, size_t co);
    std::string getNom() override{return "Baton";}
    QColor getColor() override{return Qt::cyan;}
};

