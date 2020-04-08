#include "menu.h"

menu::menu()
    :patternWidget(){

    //init widget
    _play = new QPushButton("Jouer !");
    _play->setStyleSheet("QPushButton { background-color: red; }");
    _leave = new QPushButton("Quitter :(");
    _leave->setStyleSheet("QPushButton { background-color: red; }");


    _verticalLayout = new QVBoxLayout();
    _verticalLayout->addWidget(_play);
    _verticalLayout->addWidget(_leave);


    setLayout(_verticalLayout);
    _verticalLayout->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);

    QObject::connect(_leave, &QPushButton::clicked, this, &patternWidget::close);
}

void menu::hideMenu(){
    setVisible(false);
    setEnabled(false);
}

void menu::showMenu(){
    setVisible(true);
    setEnabled(true);
}
