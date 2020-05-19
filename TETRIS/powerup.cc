#include "powerup.h"

powerUp::powerUp()
    :patternWidget(){
    //ecrase la derniere ligne
    _lesPowerUp.push_back(new powerButton("ecraser une ligne : 5 coins",this, 5, "eraseLine"));
    //passe au lvl suivant
    _lesPowerUp.push_back(new powerButton("passer au lvl suivant : 5 coins",this, 5, "nextLvl"));
    //ralenti la clock general
    _lesPowerUp.push_back(new powerButton("ralentir la vitesse : 5 coins", this, 5, "slowSpeed"));
    //fait apparaitre un tetrimino bombe
    _lesPowerUp.push_back(new powerButton("tetrimino bombe : 5 coins", this, 5, "tetriminoBombe"));

    _lesPowerUp.push_back(new powerButton("retour", this, 0, "back"));

    _lay = new QVBoxLayout();
    setLayout(_lay);

    for(auto x : _lesPowerUp){
        x->setFont(getFont());
        _lay->addWidget(x);
    }

    _lay->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
}

void powerUp::hidePower(){
    setVisible(false);
    setEnabled(false);
}

void powerUp::showPower(){
    setVisible(true);
    setEnabled(true);
}
