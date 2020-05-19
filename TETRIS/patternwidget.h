#pragma once

#include <QWidget>
#include <QRandomGenerator>
#include <vector>

/*
 *  Class qui est a la base de toutes les fenetre du jeu
*/

class patternWidget : public QWidget
{
public:
    patternWidget();

    int getWidth(){return _width;}
    int getheight(){return _height;}
    QFont getFont(){return  _font;}

    //nous genener notre vector de Qcolor pour la ceinture de carré colorés
    void randomizeQColorVector();

    void paintEvent(QPaintEvent *);
private:
    int _width;
    int _height;
    QRandomGenerator _rand;
    std::vector<QColor> _colors;
    QFont _font;
};

