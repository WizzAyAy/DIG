#pragma once
#include <string>
#include <vector>

class moteur
{
public:
    moteur()=default;
    int calcul(std::vector<std::string> attr);
};
