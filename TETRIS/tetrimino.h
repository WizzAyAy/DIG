#pragma once

#include <vector>
#include <string>
#include <QColor>

/*
 * class virtuel pure pour la creation de tous les tetriminos
*/

struct pos{
    size_t ligne;
    size_t col;
};

class tetrimino
{
public:
    /*-------------------CONTRUCTEUR && INIT-------------------*/
    //normalement constructeur par default jamais appelé
    tetrimino() = default;
    virtual ~tetrimino() = default;
    tetrimino(size_t li, size_t co);


    /*-------------------TRANSFORMATION DE POSITION-------------------*/
    void rotateLeft();
    void rotateRight();

    void transLeft();
    void transRight();

    void transDown();

    /*-------------------GETTER && SETTER-------------------*/
    std::vector<pos> getLesPos(){return _lesPos;}
    virtual std::string getNom() = 0;
    virtual QColor getColor() = 0;

    /*-------------------MATHS-------------------*/
    //effectue une rotation de 90 ou -90 deg selon le centre du tetrimino (angle = 1 ou -1)
    pos rotatePoint(float pligne, float pcol, float angle);

protected:
    pos _centre;
    std::vector<pos> _lesPos;
};
