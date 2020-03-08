#include "window.hh"

#include <string>
#include <iostream>


window::window()
    :QWidget(){
    //init des layout
    _leBas = new QHBoxLayout;
    _gridGauche = new QGridLayout;
    _gridDroite = new QGridLayout;
    _layoutOut = new QVBoxLayout;

    //init des widgets
    _afficheur = new QLineEdit("", this);
    _afficheur->setReadOnly(true);
    _afficheur->setObjectName("affi");
    _afficheur->setStyleSheet("background-color: '#9eff6e'");

    _operateur = new QLineEdit("", this);
    _operateur->setReadOnly(true);
    _operateur->setMaximumWidth(35);
    _afficheur->setObjectName("resu");
    _operateur->setStyleSheet("background-color: '#9eff6e'");

    _layoutOut->addStretch(1);
    _layoutOut->addWidget(_afficheur);
    _layoutOut->addWidget(_operateur, 1,Qt::AlignRight);
    _layoutOut->setMargin(0);
    _layoutOut->setSpacing(0);

    initChiffre();
    initSymbole();

    _egale = new mesButtons("=", this);

    //positionement des differents widgets dans les layouts
    _leBas->addStretch(1);
    _leBas->addLayout(_gridGauche);
    _leBas->addStretch(1);
    _leBas->addLayout(_gridDroite);
    _leBas->addStretch(1);
    _layoutOut->addLayout(_leBas);
    _layoutOut->addStretch(1);
    setLayout(_layoutOut);
    initGridGauche();
    initGridDroite();

    connectAll();
}

void window::initChiffre(){
    _lesChifres.clear();
    for(int i = 9; i != -1; i--){
        QString temp = QString::fromStdString(std::to_string(i));
        _lesChifres.push_back(new mesButtons(temp, this));
    }
    _lesChifres.push_back(new mesButtons("0", this));
}

void window::initSymbole(){
    _lesSymboles.clear();
    _lesSymboles.push_back(new mesButtons(",",this));
    _lesSymboles.push_back(new mesButtons("+",this));
    _lesSymboles.push_back(new mesButtons("-",this));
    _lesSymboles.push_back(new mesButtons("*",this));
    _lesSymboles.push_back(new mesButtons("/",this));
    _lesSymboles.push_back(new mesButtons("(",this));
    _lesSymboles.push_back(new mesButtons(")",this));
    _lesSymboles.push_back(new mesButtons("^2",this));
}

void window::initGridGauche(){
    //positionement des chiffres et de la virgules dans le layout _gridGauche
    int col = 2;
    int lig = 0;
    for(auto x : _lesChifres){
        if(x->text() == "0")
            _gridGauche->addWidget(x,lig,0,1,2);
        else
            _gridGauche->addWidget(x,lig,col,1,1);

        --col;
        if(col == -1) {
            col = 2;
            ++lig;
        }
    }
    _gridGauche->addWidget(_lesSymboles.at(0),lig,2,1,1);
    _gridGauche->setSpacing(0);
}

void window::initGridDroite(){
    int col = 0;
    int lig = 0;
    auto it = _lesSymboles.begin();
    it++;
    for(; it != _lesSymboles.end(); it++){
        _gridDroite->addWidget(*it,lig,col,1,1);
        ++col;
        if(col%2 == 0) {
            col = 0;
            ++lig;
        }
    }
    _gridDroite->addWidget(_egale,lig,col,1,1);
    _gridDroite->setSpacing(0);

}

void window::connectAll(){
    for(mesButtons* x : _lesChifres)
        QObject::connect(x, &mesButtons::jeTeClique, this, &window::onclickbutton);

    for(mesButtons* x : _lesSymboles)
        QObject::connect(x, &mesButtons::jeTeClique, this, &window::onclickbutton);

    QObject::connect(_egale, &mesButtons::jeTeClique, this, &window::onclickbutton);
}

void window::onclickbutton(QString s){
    emit signalButton(s);
}

void window::slotligne(QString s){
    QString tmp = _afficheur->text();
    tmp += s;
    _afficheur->setText(tmp);
}

void window::slotOpe(QString s){
    QString tmp = _afficheur->text();
    tmp += s;
    _afficheur->setText(tmp);
    _operateur->setText(s);
}

void window::slotegal(double s){
    std::cout << s << std::endl;
    QString number = QString::number(s);
    _operateur->setText("");
    _afficheur->setText(number);
}
