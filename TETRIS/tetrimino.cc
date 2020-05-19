#include "tetrimino.h"

#include <stdlib.h>
#include <cmath>
#include <iostream>


/*-------------------CONTRUCTEUR && INIT-------------------*/
tetrimino::tetrimino(size_t li, size_t co)
    :_centre({li,co}){
    _lesPos.push_back(_centre);
}

/*-------------------TRANSFORMATION DE POSITION-------------------*/
void tetrimino::rotateLeft(){
    if(getNom() == "carre") return;
    std::vector<pos> lesNouvellesPositions;

    for(auto &i : _lesPos){
        lesNouvellesPositions.push_back(rotatePoint(i.ligne,i.col,1));
    }
    //lesNouvellesPositions devient mon nouveau vector de positions
    _lesPos.clear();
    _lesPos = lesNouvellesPositions;
    //normalement le _centre ne change pas ...
    _centre = _lesPos.at(0);
}

void tetrimino::rotateRight(){
    if(getNom() == "carre") return;
    std::vector<pos> lesNouvellesPositions;

    for(auto &i : _lesPos){
        lesNouvellesPositions.push_back(rotatePoint(i.ligne,i.col,-1));
    }
    //lesNouvellesPositions devient mon nouveau vector de positions
    _lesPos.clear();
    _lesPos = lesNouvellesPositions;
    //normalement le _centre ne change pas ...
    _centre = _lesPos.at(0);
}

void tetrimino::transLeft(){
    for(auto &x : _lesPos){
        //je decale juste toutes les pos d'une case vers la gauche
        x.col--;
    }
    _centre.col--;
}

void tetrimino::transRight(){
    bool collerGauche = false;
    for(auto x : _lesPos) if(x.col == 9) collerGauche = true;
    if(collerGauche){
         //std::cout << "deplacement pas possible\n";
    }
    else{
        for(auto &x : _lesPos){
            //je decale juste toutes les pos d'une case vers la droite
            x.col++;
        }
        _centre.col++;
    }
}

void tetrimino::transDown(){
    for(auto &x : _lesPos){
        //je decale juste toutes les pos d'une case vers le bas
        x.ligne++;
    }
    _centre.ligne++;
}

pos tetrimino::rotatePoint(float pligne, float pcol, float angle){
    //angle = 1 ou -1 sens horraires anti horraires
    //Vc vecteur du point au centre
    int VcCol;
    int VcLig;

    VcCol = pcol - _centre.col;
    VcLig = pligne - _centre.ligne;

    //Vr vecteur avec la rotation
    int VrCol;
    int VrLig;

    VrCol = -angle*VcLig;
    VrLig = angle*VcCol;

    //pos c'est la position final
    pos final;

    final.col = _centre.col + VrCol;
    final.ligne = _centre.ligne + VrLig;

    return final;
}

