#pragma once

#include <vector>
#include <QColor>
#include <QObject>
#include <string>

#include "tetrimino.h"

/*
 *  cette classe est la base du jeu, en effet elle est son moteur de jeu
 *  les regles, la generation des pieces se font ici.
*/

struct block{
    bool boolean;
    QColor color;
};

class engine : public QObject
{
    Q_OBJECT
signals:
    void nbLineErase(const int & nb);
    void tetriminoChanged();
    void endOfGame();
    void sound(std::string name);

public:
    /*-------------------CONTRUCTEUR && INIT-------------------*/
    engine();
    void restartEngine();
    //initialise la grille du tetris
    void initMatrix();
    void initVectorTetrimino();
    //init le tetrimino qui est en attente a null
    void initHoldingTetrimino(){_holdingTetrimino = nullptr;}
    //ajoute un tetrimino aleatoir dans le vector de Tetrimino
    void addRandomTetrimino();

    /*-------------------GETTER && SETTER-------------------*/
    std::vector<std::vector<block>> getMatrix(){return _matrix;}
    std::vector<tetrimino*> getNextTetriminos(){return _nextTetriminos;}
    tetrimino* getCurrentTetrimino(){return _currentTetrimino;}
    tetrimino* getHoldingTetrimino(){return _holdingTetrimino;}
    unsigned int getNbCol(){return _nbCol;}
    unsigned int getNbLig(){return _nbLig;}

    void setCurrentTetrimino(tetrimino* t){_currentTetrimino = t;}
    //setLeTetrimino holder avec le courant mais avec les pos de base;
    void setHoldingTetrimino();
    void setHoldingTetrimino(std::string const & n);

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
    //prend le prochain tetrimino et met a jour le vector des next
    void goNextTetrimino();

    //effectue la rotation a gauche/droite sur le tetrimino courant
    void rotateLeftTetrimino();
    void rotateRightTetrimino();

    //effectue la translation a droite/droite sur le tetrimino courant
    void TransRightTetrimino();
    void TransLeftTetrimino();

    //teleport en bas le tetri courant
    void teleportDown();

    /*-------------------POWER-------------------*/
    //retient le tetrimino courrant
    void holdCurrentTetrimino();
    //ecrase la derniere ligne
    void powerEraseLine();
    //change le courrant en bombe
    void currentBecomeBomb();
    //fait exploser le tetrimino courant (tetriminoBombe)
    void explosionBombe();

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
    tetrimino* _holdingTetrimino;
    std::vector<tetrimino*> _nextTetriminos;
    bool _holdThisTurn;
};
