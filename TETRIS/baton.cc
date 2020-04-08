#include "baton.h"

baton::baton(size_t li, size_t co)
    :tetrimino(li,co){
    _lesPos.push_back({_centre.ligne, _centre.col-1});
    _lesPos.push_back({_centre.ligne, _centre.col+1});
    _lesPos.push_back({_centre.ligne, _centre.col+2});
}
