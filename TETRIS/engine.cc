#include "engine.hh"

#include <iostream>
#include <algorithm>

engine::engine()
    :_nbCol(10), _nbLig(20){
    initMatrix();
}

void engine::initMatrix(){
    std::vector<bool> tmp;
    for(size_t i = 0; i < _nbCol; i++){
        tmp.push_back(false);
    }
    for(size_t i = 0; i < _nbLig; i++){
        _matrix.push_back(tmp);
    }
}

bool engine::canGoDown(const size_t lig, const size_t col){
    if(lig == 20) return false;
    else if(_matrix.at(lig+1).at(col) == true) return false;
    else return true;
}

bool engine::fullLine(const std::vector<bool> lig){
    bool tmp = true;
    for(auto x : lig){
        tmp = tmp && x;
    }
    return tmp;
}

void engine::eraseLine(){
   int nbRemov = 0;
   auto it = std::remove_if(_matrix.begin(), _matrix.end(),
   [&nbRemov](std::vector<bool> tmp){
            if (fullLine(tmp)){
               nbRemov++;
               return true;
            }
            else return false;});
    _matrix.erase(it, _matrix.end());
    std::vector<bool> tmp;
    for(size_t i = 0; i < 11; i++){
        tmp.push_back(false);
    }
    for(int i = 0; i < nbRemov; i++){
        _matrix.insert(_matrix.begin(), tmp);
    }

}

void engine::fillLine(const size_t lig){
    for(size_t i = 0; i < _matrix.at(lig).size(); i++)
        _matrix.at(lig).at(i) = true;
}

void engine::fillcol(const size_t col){
    for(size_t i = 0; i < _matrix.size(); i++)
        _matrix.at(i).at(col) = true;
}

void engine::show(){
    int ligne = 0;
    int col = 0;
    for(auto i : _matrix){
        for(auto j : i){
            if(!j)
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

