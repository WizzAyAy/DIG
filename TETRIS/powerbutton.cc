#include "powerbutton.h"

#include <iostream>

powerButton::powerButton(const QString &text, QWidget* parent , const int &cost, const std::string &effect)
    :QPushButton(text,parent), _cost(cost), _effect(effect){
    setStyleSheet("QPushButton { "
                         "border: 2px solid #8f8f91;"
                         "border-radius: 6px;"
                         "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #f6f7fa, stop: 1 #dadbde); "
                         "min-width: 200px;"
                         "min-height: 80px; }");


    QObject::connect(this, &QPushButton::clicked, this, &powerButton::isClicked);
}

void powerButton::isClicked(){
    emit powerEmit(_cost, _effect);
}
