#include <iostream>
#include <QApplication>
#include <ctime>

#include "gestionnaire.h"

int main(int argc, char *argv[]) {

    std::srand(std::time(nullptr));

    QApplication app(argc,argv);
    gestionnaire g;
    return app.exec();
}
