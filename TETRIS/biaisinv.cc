#include "biaisinv.h"

biaisInv::biaisInv(size_t li, size_t co)
    :tetrimino(li,co){
    _lesPos.push_back({_centre.ligne, _centre.col+1});
    _lesPos.push_back({_centre.ligne+1, _centre.col});
    _lesPos.push_back({_centre.ligne+1, _centre.col-1});
}
