#pragma once

#include <vector>

class engine
{
public:
    /*-------------------CONTRUCTEUR && INIT-------------------*/
    engine();
    //initialise la grille du tetris
    void initMatrix();

    /*-------------------GETTER && SETTER-------------------*/
    std::vector<std::vector<bool>> getMatrix(){return _matrix;}
    unsigned int getNbCol(){return _nbCol;}
    unsigned int getNbLig(){return _nbLig;}

    /*-------------------VERIF-------------------*/
    //return true si avec cette pos un block peut descendre
    bool canGoDown(const size_t lig, const size_t col);
    //retourn true si une ligne est complete
    static bool fullLine(const std::vector<bool> lig);

    /*-------------------CHANGEMENT D ETAT-------------------*/
    void eraseLine();

    /*-------------------AIDE DEBUG-------------------*/
    //remplit une ligne
    void fillLine(const size_t lig);
    //remplit une colonne
    void fillcol(const size_t col);
    //affiche la grille
    void show();
    //ajoute un block en lig col
    void addBlock(const int lig, const int col){_matrix.at(lig).at(col) = true;}

private:
    std::vector<std::vector<bool>> _matrix;
    unsigned int _nbCol;
    unsigned int _nbLig;
};
