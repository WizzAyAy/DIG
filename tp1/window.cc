#include "window.hh"

#include <iostream>

window::window()
    :QWidget()
{
    QHBoxLayout* lay = new QHBoxLayout;

    _op1 = new QSpinBox(this);
    _op2 = new QSpinBox(this);
    _op1->setMaximum(999);
    _op2->setMaximum(999);

    _symbole = new QComboBox(this);
    _symbole->addItem("+");
    _symbole->addItem("-");
    _symbole->addItem("/");
    _symbole->addItem("*");

    _egale = new QPushButton("=",this);

    _resultat = new QLCDNumber(4,this);

    lay->addWidget(_op1);
    lay->addWidget(_symbole);
    lay->addWidget(_op2);
    lay->addWidget(_egale);
    lay->addWidget(_resultat);

    lay->setMargin(50);
    lay->setSpacing(20);
    setLayout(lay);

}

void window::onclickEgal(){
    emit signalWindow({std::to_string(_op1->value()), std::to_string(_op2->value()),_symbole->currentText().toStdString()});
}

void window::changeRes(int a)
{
    _resultat->display(a);
}


