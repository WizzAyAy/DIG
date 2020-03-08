#pragma once

#include "mesbuttons.hh"

#include <QtWidgets>
#include <vector>

class window : public QWidget
{
    Q_OBJECT
public:
    window();
    void initChiffre();
    void initSymbole();
    void initGridGauche();
    void initGridDroite();
    void connectAll();
    void onclickbutton(QString s);
signals:
    void signalButton(QString s);
public slots:
    void slotligne(QString s);
    void slotOpe(QString s);
    void slotegal(double s);
private:

    //--------4 Layouts--------//
    QGridLayout* _gridGauche;
    QGridLayout* _gridDroite;
    QVBoxLayout* _layoutOut;
    QHBoxLayout* _leBas;

    //--------les Widgets--------//

    std::vector<mesButtons*> _lesChifres; //de 0 a 9
    std::vector<mesButtons*> _lesSymboles; // grid droite + ',' mais pas le =
    mesButtons* _egale;

    QLineEdit* _afficheur;
    QLineEdit* _operateur;
};


