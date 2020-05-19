#pragma once
#include "engine.h"
#include "patternwidget.h"
#include "powerup.h"

#include <QtWidgets>
#include <string>
#include <vector>
#include <iostream>


/*
 *  cette classe marche en duo avec l'engine.
 *  elle socupe du visuel du jeu et des connexcion avec l'utilisateur comme les transmitions au clavier
*/

class game : public patternWidget
{
        Q_OBJECT

public:
    /*-------------------CONTRUCTEUR && INIT-------------------*/
    game();
    //permet de recommencer une partie (init tous les attributs)
    void restartGame();
    //cache le widget
    void hideGame();
    //rend visible ce widget
    void showGame();

    /*-------------------LE GRAPHIQUE-------------------*/
    //methode qui va dessiné sur notre Widget
    void paintEvent(QPaintEvent *p);


    /*-------------------LES TOUCHES-------------------*/
    //methode qui capte les inputs
    void keyPressEvent(QKeyEvent *event);

    /*-------------------GETTER && SETTER-------------------*/
    void setSpeed(const int &speed){_speed = speed; _myTimer->start(_speed);}
    int getScore(){return _score;}

    /*-------------------AUTRE-------------------*/
    //methode qui va au menu pricipale
    void goMenu();
    //fin de la partie nous envoie vers l'ecran de fin de partie
    void goEndScreen();
    //met tous les widgets de cette classe a jour
    void updateWidget();
    //ouvre le magasin des sorts
    void goShop();
    //ferme le magasin des sorts et reviens en jeux
    void comeBackFromShop();

    /*-------------------SLOTS-------------------*/
public slots:
    //permet de faire des Qconnect pour update paintEvent
    void myUpdate();
    //pareil
    void updatePaint();
    //score recu et donc ajouté au score total
    void updateScore(const int & nb);
    //execute le pouvoir
    void execPower(int cost, std::string effect);
    //slot qui est executé a la fin de la partie
    void endOfGame();
    //set les touches
    void setKey(std::vector<Qt::Key> k);
    //slot qui permet de lancer un son
    void soundFromEngine(std::string name);

    /*-------------------SIGNALS-------------------*/
signals:
    //signal emit quand on veut retourner au menu principal
    void goBackMenu();
    //signal emit quand on veut aller au endScreen
    void endScreen();
    //signal emit quand la partie est finie
    void GameOver();
    //siganl emit quand on veut emettre un son
    void sound(std::string name);
    //signal emit quand on veut changer de music
    void nextMusic();

private:
    engine e;
    powerUp _power;
    int _score;
    int _speed;
    bool _speedUp;
    int _lvl;
    int _coin;
    bool _pause;


    std::vector<Qt::Key> _key;
    QTimer* _myTimer;


    QLabel* _textScore;
    QLCDNumber* _LCDScore;

    QLabel* _textLvl;
    QLCDNumber* _LCDLvl;

    QLabel* _textCoin;
    QLCDNumber* _LCDCoin;

    QLabel* _textSpeed;
    QLCDNumber* _LCDSpeed;
};
