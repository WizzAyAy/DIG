#pragma once

#include "patternwidget.h"

#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <string>

/*
 *  cette classe qui herite de pattern Widget represente l'ecran de fin ou l'on rentre son nom pour cree un nouvel enregistrement avec le score de la partie
*/

class endScreen : public patternWidget
{
public:
    endScreen();
    //montre/cache et active/desacive cet objet
    void hideEndScreen();
    void showEndScreen();

    //update un QLabel pour y inseré le world record courrant
    void updateWordlRecord(int const & score, std::string const & name, std::string const & date);

    QPushButton* getButton(){return _button;}
    std::string getLineEdit(){return _lineEdit->text().toStdString();}

    void paintEvent(QPaintEvent *s);

private:
    QLabel* _label;
    QLineEdit* _lineEdit;
    QPushButton* _button;
    QLabel* _labelWorldRecord1;
    QLabel* _labelWorldRecord2;

    QVBoxLayout* _layout;
};
