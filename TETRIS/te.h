#pragma once

#include "tetrimino.h"

class te : public tetrimino
{
public:
    te(size_t li, size_t co);
    std::string getNom() override{return "te";}
    QColor getColor() override{return Qt::magenta;}
};
