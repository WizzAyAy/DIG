#pragma once

#include <vector>
#include <QColor>
#include <QObject>

#include "tetrimino.h"

struct block{
    bool boolean;
    QColor color;
};

class engine : public QObject
{
    Q_OBJECT
signals:
    void nbLineErase(const int & score);
    void tetriminoChanged();
    void endOfGame();

public:
    /*-------------------CONTRUCTEUR && INIT-------------------*/
    engine();
    void restartEngine();
    //initialise la grille du tetris
    void initMatrix();
    void initVectorTetrimino();
    void addRandomTetrimino();

    /*-------------------GETTER && SETTER-------------------*/
    std::vector<std::vector<block>> getMatrix(){return _matrix;}
    std::vector<tetrimino*> getNextTetriminos(){return _nextTetriminos;}
    unsigned int getNbCol(){return _nbCol;}
    unsigned int getNbLig(){return _nbLig;}

    void setCurrentTetrimino(tetrimino* t){_currentTetrimino = t;}

    /*-------------------VERIF-------------------*/
    //return true si avec cette pos un block peut descendre
    bool canGoDown(const size_t lig, const size_t col);
    //return true si les coordonnées appartienne au vector de pos du tetrimino courrant
    bool posBelongToCurrent(const size_t lig, const size_t col);
    //fait tomber le block en lig col
    void goDown(const size_t lig, const size_t col);

    //return true si le terimino courant peut descendre
    bool canTetriminoGoDown();
    //fait "tomber le terimino courant
    void goDownTetrimino();

    //reutrn true si le tetrimino courant peut aller vers la gauche/droite
    bool canTetriminoGoLeft();
    bool canTetriminoGoRight();

    //return true si le tetrimino peut tourner
    bool canTetriminoTurnLeft();
    bool canTetriminoTurnRight();

    //retourn true si une ligne est complete
    static bool fullLine(const std::vector<block> lig);

    //return true si la case en lig col est vide
    bool emptyCase(const size_t lig, const size_t col);

    /*-------------------CHANGEMENT D ETAT-------------------*/
    //methode qui change l'etat de la matrice de t a t+1
    void updateMatrix();

    //ecrase une ligne remplit
    int eraseLine();    

    //ajoute a la matrice le tetrimino courant
    void addCurrentTetrimino();
    //supprime les coordonnées du tetriminos courant dans la matrice
    void suppCurrentTetrimino();

    //effectue la rotation a gauche/droite sur le tetrimino courant
    void rotateLeftTetrimino();
    void rotateRightTetrimino();

    //effectue la translation a droite/droite sur le tetrimino courant
    void TransRightTetrimino();
    void TransLeftTetrimino();

    //teleport en bas le tetri courant
    void teleportDown();

    /*-------------------AIDE DEBUG-------------------*/
    //remplit une ligne
    void fillLine(const size_t lig);
    //remplit une colonne
    void fillcol(const size_t col);
    //affiche la grille
    void show();
    //ajoute un block en lig col
    void addBlock(const size_t lig, const size_t col){_matrix.at(lig).at(col).boolean = true;}

private:
    std::vector<std::vector<block>> _matrix;
    unsigned int _nbCol;
    unsigned int _nbLig;
    tetrimino* _currentTetrimino;
    std::vector<tetrimino*> _nextTetriminos;
};
