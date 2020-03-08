#include <iostream>
#include <QApplication>


#include "engine.hh"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    engine e;
    return app.exec();
}

