#pragma once

#include "patternwidget.h"

#include <QtWidgets>

/*
*   class qui represente le menu principal du jeu
*/

class menu : public patternWidget
{
public:
    menu();
    //montre/cache et active/desactive le menu
    void hideMenu();
    void showMenu();

    QPushButton* getPlayButton(){return _play;}
    QPushButton* getHelperButton(){return _helper;}

    void paintEvent(QPaintEvent *s);

private:
    QPushButton* _play;
    QPushButton* _leave;
    QPushButton* _helper;

    QVBoxLayout* _verticalLayout;
};
