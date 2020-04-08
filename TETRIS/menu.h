#pragma once

#include "patternwidget.h"

#include <QtWidgets>

class menu : patternWidget
{
    Q_OBJECT
public:
    menu();
    void hideMenu();
    void showMenu();
    QPushButton* getPlayButton(){return _play;}

signals:
    void play();

private:
    QPushButton* _play;
    QPushButton* _leave;

    QVBoxLayout* _verticalLayout;
};
