#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>

#include "engine.h"
#include "tetrimino.h"

#include "baton.h"
#include "carre.h"
#include "te.h"
#include "lambda.h"
#include "gamma.h"
#include "biais.h"
#include "biaisinv.h"
#include "tetriminobombe.h"


/*-------------------CONTRUCTEUR && INIT-------------------*/
engine::engine()
    :QObject(), _nbCol(10), _nbLig(20){
    initMatrix();
    initVectorTetrimino();
    initHoldingTetrimino();

    _holdThisTurn = false;

    setCurrentTetrimino(_nextTetriminos.front());
    _nextTetriminos.erase(_nextTetriminos.begin());
    emit tetriminoChanged();
}

void engine::restartEngine(){
    _matrix.clear();
    initMatrix();

    _nextTetriminos.clear();
    initVectorTetrimino();

    initHoldingTetrimino();

    _holdThisTurn = false;

    setCurrentTetrimino(_nextTetriminos.front());
    _nextTetriminos.erase(_nextTetriminos.begin());
    addCurrentTetrimino();
    emit tetriminoChanged();
}

void engine::initMatrix(){
    std::vector<block> tmp;
    for(size_t i = 0; i < _nbCol; i++){
        tmp.push_back({false,Qt::red});
    }
    for(size_t i = 0; i < _nbLig; i++){
        _matrix.push_back(tmp);
    }
}

void engine::initVectorTetrimino(){
    for(int i = 0; i < 5; i++){
        addRandomTetrimino();
    }
}

void engine::addRandomTetrimino(){
    int tmp = std::rand()/((RAND_MAX + 1)/7);
    //std::cout << tmp << std::endl;
    if(tmp == 0) _nextTetriminos.push_back(new baton(0,4));
    if(tmp == 1) _nextTetriminos.push_back(new carre(0,4));
    if(tmp == 2) _nextTetriminos.push_back(new te(0,4));
    if(tmp == 3) _nextTetriminos.push_back(new lambda(0,4));
    if(tmp == 4) _nextTetriminos.push_back(new gamma(0,4));
    if(tmp == 5) _nextTetriminos.push_back(new biais(0,4));
    if(tmp == 6) _nextTetriminos.push_back(new biaisInv(0,4));
}

void engine::setHoldingTetrimino(){
    if(_currentTetrimino->getNom() == "baton") _holdingTetrimino = new baton(0,4);
    if(_currentTetrimino->getNom() == "carre") _holdingTetrimino = new carre(0,4);
    if(_currentTetrimino->getNom() == "te") _holdingTetrimino = new te(0,4);
    if(_currentTetrimino->getNom() == "lambda") _holdingTetrimino = new lambda(0,4);
    if(_currentTetrimino->getNom() == "gamma") _holdingTetrimino = new gamma(0,4);
    if(_currentTetrimino->getNom() == "biais") _holdingTetrimino = new biais(0,4);
    if(_currentTetrimino->getNom() == "biaisInv") _holdingTetrimino = new biaisInv(0,4);
}

void engine::setHoldingTetrimino(const std::string &n){
    if(n == "baton") _holdingTetrimino = new baton(0,4);
    if(n == "carre") _holdingTetrimino = new carre(0,4);
    if(n == "te") _holdingTetrimino = new te(0,4);
    if(n == "lambda") _holdingTetrimino = new lambda(0,4);
    if(n == "gamma") _holdingTetrimino = new gamma(0,4);
    if(n == "biais") _holdingTetrimino = new biais(0,4);
    if(n == "biaisInv") _holdingTetrimino = new biaisInv(0,4);
}

/*-------------------VERIF-------------------*/
bool engine::canGoDown(const size_t lig, const size_t col){
    //je dois verifier que aucune case n'est en dessous
    //si la case est en dessous alors ce n'est pas une case du tetrimino courrant
    //que je ne suis pas deja en bas
    if(lig >= 19) return false;
    else if(_matrix.at(lig+1).at(col).boolean == true){
        if(!posBelongToCurrent(lig+1, col)) return false;
    }
    return true;
}

bool engine::posBelongToCurrent(const size_t lig, const size_t col){
    for(auto x : _currentTetrimino->getLesPos()){
        if(x.col == col && x.ligne == lig) return true;
    }
    return false;
}

void engine::goDown(const size_t lig, const size_t col){
    _matrix.at(lig+1).at(col).boolean = true;
    _matrix.at(lig).at(col).boolean   = false;
}

bool engine::canTetriminoGoDown(){
    bool res = true;
    for(auto x : _currentTetrimino->getLesPos()){
        res = res & canGoDown(x.ligne, x.col);
    }
    return res;
}

void engine::goDownTetrimino(){
    suppCurrentTetrimino();
    _currentTetrimino->transDown();
    addCurrentTetrimino();
}

bool engine::canTetriminoGoLeft(){
    //je dois regarder si le tetrimino peut aller a gauche

    //soit un block est deja sur la limite donc non
    //soit ya deja une block sur le passage donc non
    for(auto x : _currentTetrimino->getLesPos()){
        if(x.col == 0) return false;
        if(_matrix.at(x.ligne).at(x.col-1).boolean == true) return false;
    }
    return true;
}

bool engine::canTetriminoGoRight(){
    for(auto x : _currentTetrimino->getLesPos()){
        if(x.col == 9) return false;
        if(_matrix.at(x.ligne).at(x.col+1).boolean == true) return false;
    }
    return true;
}

bool engine::canTetriminoTurnLeft(){
    std::vector<pos> lesNouvellesPositions;

    for(auto i : _currentTetrimino->getLesPos()){
        lesNouvellesPositions.push_back(_currentTetrimino->rotatePoint(i.ligne,i.col,1));
    }

    for(auto x : lesNouvellesPositions){
        if(x.col < 0 || x.col > 9) return false;
        if(x.ligne < 0 || x.ligne > 19) return false;
        if(_matrix.at(x.ligne).at(x.col).boolean == true) return false;

    }
    return true;
}

bool engine::canTetriminoTurnRight(){
    std::vector<pos> lesNouvellesPositions;

    for(auto i : _currentTetrimino->getLesPos()){
        lesNouvellesPositions.push_back(_currentTetrimino->rotatePoint(i.ligne,i.col,-1));
    }

    for(auto x : lesNouvellesPositions){
        if(x.col < 0 || x.col > 9) return false;
        if(x.ligne < 0 || x.ligne > 19) return false;
        if(_matrix.at(x.ligne).at(x.col).boolean == true) return false;
    }
    return true;
}

bool engine::fullLine(const std::vector<block> lig){
    for(auto x : lig){
        if(!x.boolean) return false;
    }
    return true;
}

bool engine::emptyCase(const size_t lig, const size_t col){
    return !(_matrix.at(lig).at(col).boolean);
}

/*-------------------CHANGEMENT D ETAT-------------------*/
void engine::updateMatrix(){
    //le tetrimino courant peut se deplacer vers le bas donc je le garde
    if(canTetriminoGoDown()) {
        //std::cout << "le tetrimino courant descend d'une ligne (ligne ++)" << std::endl;
        goDownTetrimino();
    }
    //le tetrimino courant ne peut pas descendre d'une case donc je le "bloque" et je choisis le suivant
    else {
        //je regarde si il a detruit des lignes quand il s'est stopé
        int nbErase = eraseLine();
        if (nbErase > 0){
            //std::cout << "le socre augmente\n";
            emit nbLineErase(nbErase);
        }
        if(_currentTetrimino->getNom() == "bombe") explosionBombe();
        //je prend le suivant en ajoutant un autre
        goNextTetrimino();
        //le tetrimino qui vient de pop ne peut pas descendre donc c'est la fin de la partie
        if(!canTetriminoGoDown()){
            emit endOfGame();
            emit sound("gameOver");
        }
        emit tetriminoChanged();
        _holdThisTurn = false;
    }
}

int engine::eraseLine(){
   int nbRemov = 0;
   auto it = std::remove_if(_matrix.begin(), _matrix.end(),
   [&nbRemov](std::vector<block> tmp){
            if (fullLine(tmp)){
               nbRemov++;
               return true;
            }
            else return false;
        });
    _matrix.erase(it, _matrix.end());
    std::vector<block> tmp;
    for(size_t i = 0; i < 10; i++){
        tmp.push_back({false,Qt::red});
    }
    for(int i = 0; i < nbRemov; i++){
        _matrix.insert(_matrix.begin(), tmp);
    }
    return nbRemov;
}

void engine::addCurrentTetrimino(){
    try {
        for(auto x : _currentTetrimino->getLesPos()){
            _matrix.at(x.ligne).at(x.col).boolean = true;
            _matrix.at(x.ligne).at(x.col).color = _currentTetrimino->getColor();
        }
    }
    catch (const std::out_of_range& oor) {
       std::cerr << "Attention votre tetrimino a ajouter n'est pas entierement dans la grille --> " << oor.what() << '\n';
    }
}

void engine::suppCurrentTetrimino(){
    try {
        for(auto x : _currentTetrimino->getLesPos()){
            _matrix.at(x.ligne).at(x.col).boolean = false;
        }
    }
    catch (const std::out_of_range& oor) {
       std::cerr << "Attention votre tetrimino a detruire n'est pas entierement dans la grille --> " << oor.what() << '\n';
    }
}

void engine::goNextTetrimino(){
    addRandomTetrimino();
    setCurrentTetrimino(_nextTetriminos.front());
    _nextTetriminos.erase(_nextTetriminos.begin());
    addCurrentTetrimino();
}

void engine::rotateLeftTetrimino(){
    suppCurrentTetrimino();
    if(canTetriminoTurnLeft()){
        _currentTetrimino->rotateLeft();
        emit sound("move");
    }
    else{
        //std::cout << "rotation vers la gauche impossible\n";
        emit sound("moveFail");
    }
    addCurrentTetrimino();
}

void engine::rotateRightTetrimino(){
    suppCurrentTetrimino();
    if(canTetriminoTurnRight()){
        _currentTetrimino->rotateRight();
        emit sound("move");
    }
    else{
        //std::cout << "rotation vers la droite impossible\n";
        emit sound("moveFail");
    }
    addCurrentTetrimino();
}

void engine::TransRightTetrimino(){
    //je supprime le tetrimino avant pour check comme j'ai pas de probleme avec ses propres pos
    suppCurrentTetrimino();
    if(canTetriminoGoRight()){
        _currentTetrimino->transRight();
        emit sound("move");
    }
    else{
        //std::cout << "movement vers la droite impossible\n";
        emit sound("moveFail");
    }
    addCurrentTetrimino();
}

void engine::TransLeftTetrimino(){
    //je supprime le tetrimino avant pour check
    suppCurrentTetrimino();
    if(canTetriminoGoLeft()){
        _currentTetrimino->transLeft();
        emit sound("move");
    }
    else{
        //std::cout << "movement vers la gauche impossible\n";
        emit sound("moveFail");
    }
    addCurrentTetrimino();
}

void engine::teleportDown(){
    while(canTetriminoGoDown()){
        updateMatrix();
    }
    updateMatrix();

}

void engine::holdCurrentTetrimino(){
    if(!_holdThisTurn){
        emit sound("hold");
        suppCurrentTetrimino();
        if(_holdingTetrimino == nullptr){
            setHoldingTetrimino();
            goNextTetrimino();
        }
        else{
            tetrimino* tmp = _currentTetrimino;
            _currentTetrimino = _holdingTetrimino;
            setHoldingTetrimino(tmp->getNom());

            addCurrentTetrimino();
            emit tetriminoChanged();
        }
        _holdThisTurn = true;
    }
}

void engine::powerEraseLine(){
    suppCurrentTetrimino();
    _matrix.pop_back();
    std::vector<block> tmp;
    for(size_t i = 0; i < 10; i++){
        tmp.push_back({false,Qt::red});
    }

    _matrix.insert(_matrix.begin(), tmp);
    addCurrentTetrimino();
    emit tetriminoChanged();
}

void engine::currentBecomeBomb(){
    suppCurrentTetrimino();
    setCurrentTetrimino(new tetriminoBombe(0,4));
    addCurrentTetrimino();
}

void engine::explosionBombe(){
    sound("explosion");
    int col = _currentTetrimino->getLesPos().at(0).col;
    int lig = _currentTetrimino->getLesPos().at(0).ligne;
    for(int i = -2; i < 3; i++){
        for(int j = -2; j < 3; j++){
            try {_matrix.at(lig+i).at(col+j).boolean = false;}
            catch (...) {}
        }
    }
}

/*-------------------AIDE DEBUG-------------------*/
void engine::fillLine(const size_t lig){
    for(size_t i = 0; i < _matrix.at(lig).size(); i++)
        _matrix.at(lig).at(i).boolean = true;
}

void engine::fillcol(const size_t col){
    for(size_t i = 0; i < _matrix.size(); i++)
        _matrix.at(i).at(col).boolean = true;
}

void engine::show(){
    int ligne = 0;
    int col = 0;
    for(auto i : _matrix){
        for(auto j : i){
            if(!j.boolean)
            std::cout <<  "| (" << ligne << "," << col << ")";
            else
            std::cout <<  "|X(" << ligne << "," << col << ")";
            col++;
        }
        col = 0;
        ligne++;
        std::cout << "|" << std::endl;
    }
}

