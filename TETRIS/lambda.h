#pragma once

#include "tetrimino.h"

class lambda : public tetrimino
{
public:
    lambda(size_t li, size_t co);
    std::string getNom() override{return "lambda";}
    QColor getColor() override{return QColor(255,178,13);}
};
