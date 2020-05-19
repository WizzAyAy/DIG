#pragma once

#include "tetrimino.h"

/*
 *  tetrimino un peu special mais pas par sa construction
*/

class tetriminoBombe : public tetrimino
{
public:
    tetriminoBombe(size_t li, size_t co);
    std::string getNom() override{return "bombe";}
    QColor getColor() override{return Qt::black;}
};


