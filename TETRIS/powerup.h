#pragma once

#include "patternwidget.h"
#include "powerbutton.h"

#include <vector>
#include <QVBoxLayout>

/*
 * class ou sont stocké tous mes power up
*/

class powerUp : public patternWidget
{
public:
    powerUp();
    std::vector<powerButton*> getlesPowerUp(){return _lesPowerUp;}

    void hidePower();
    void showPower();
private:
    std::vector<powerButton*> _lesPowerUp;
    QVBoxLayout* _lay;
};
