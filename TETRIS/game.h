#pragma once
#include "engine.h"
#include "patternwidget.h"

#include <QtWidgets>



class game : public patternWidget
{
        Q_OBJECT

public:
    /*-------------------CONTRUCTEUR && INIT-------------------*/
    game();
    void restartGame();
    void hideGame();
    /*-------------------LE GRAPHIQUE-------------------*/
    void paintEvent(QPaintEvent *);

    /*-------------------LES TOUCHES-------------------*/
    void keyPressEvent(QKeyEvent *event);

    /*-------------------GETTER && SETTER-------------------*/
    void setSpeed(const int &speed){_speed = speed; _myTimer->start(_speed);}
    int getScore(){return _score;}

    /*-------------------AUTRE-------------------*/
    void goMenu();

    /*-------------------SLOTS-------------------*/
public slots:
    void myUpdate();
    void updatePaint();
    /*-------------------SIGNALS-------------------*/
signals:
    void goBackMenu();

private:
    engine e;
    int _score;
    int _speed;
    int _lvl;
    bool _pause;
    QTimer* _myTimer;
    QLabel* _textScore;
    QLCDNumber* _LCDScore;

};
