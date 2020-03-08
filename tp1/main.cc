#include <iostream>
#include <QApplication>

#include "traducteur.hh"

//pkg-config --cflags --libs Qt5Widgets


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    traducteur trad;
    trad.showWindow();
    return app.exec();
}
