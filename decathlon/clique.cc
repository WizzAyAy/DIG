#include "clique.hh"

#include <iostream>

clique::clique()
    :mainwindow(), _nbclique(0){

    _clique = new QPushButton("Clique pour Demarer");
    _clique->setMinimumWidth(150);
    _labelclique = new QLabel("vous avez effectué " + QString::number(_nbclique) + " clique(s)", this);

    QVBoxLayout* lay = new QVBoxLayout();

    _layclique = new QHBoxLayout();
    _layclique->setAlignment(Qt::AlignHCenter);

    _layclique->addWidget(_labelclique);
    _layclique->addWidget(_clique);

    lay->addLayout(_layclique);
    lay->addWidget(new QLabel("vous devez cliquez 25 fois, le chrono démarre au premier clique"));
    lay->setAlignment(Qt::AlignCenter);

    setLayout(lay);

    QObject::connect(_clique, &QPushButton::clicked, this, &clique::cliquer);



}

void clique::paintEvent(QPaintEvent *event){

    QPainter painter(this);

        painter.setPen(QPen(Qt::blue,10));
        painter.drawRect(5,5,width()-10,height()-10);
        painter.setPen(QPen(Qt::white,10));
        painter.drawRect(15,15,width()-30,height()-30);
        painter.setPen(QPen(Qt::red,10));
        painter.drawRect(25,25,width()-50,height()-50);

        if(_nbclique == 1){
            _debut = std::chrono::system_clock::now();
            _clique->setText("CLIQUEEEEER");
        }
}


void clique::cliquer(){
    _nbclique++;
    if(_nbclique == 25){
        _clique->setText("Clique pour Demarer");
        _nbclique = 0;
        emit goBackMenu(mode::menu);
        _fin = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = _fin-_debut;
        auto x = std::chrono::duration_cast<std::chrono::milliseconds>(diff);
        emit pb(x.count());
    }
    _labelclique->setText("vous avez effectué " + QString::number(_nbclique) + " clique(s)");
}
