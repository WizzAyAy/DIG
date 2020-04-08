#pragma once

#include "tetrimino.h"

class gamma : public tetrimino
{
public:
    gamma(size_t li, size_t co);
    std::string getNom() override{return "gamma";}
    QColor getColor() override{return Qt::darkBlue;}
};
