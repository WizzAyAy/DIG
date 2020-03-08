#include "moteur.hh"
#include "stdexcept"


int moteur::calcul(std::vector<std::string> attr){
    int a = std::stoi(attr.at(0));
    int b = std::stoi(attr.at(1));
    std::string sym = attr.at(2);
    if(sym == "+"){
        return(a+b);
    }
    else if(sym == "-"){
        return(a-b);
    }
    else if(sym == "/"){
        if(b == 0)
            throw std::invalid_argument("div par 0");
        else
            return(a/b);
    }
    else if(sym == "*"){
        return(a*b);
    }
    return 0;
}
