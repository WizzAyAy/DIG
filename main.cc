#include <iostream>
#include <QApplication>

#include "traducteur.hh"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    traducteur t;
    t.show();
    return app.exec();
}
