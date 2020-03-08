#include "mainwindow.hh"

mainwindow::mainwindow()
    :QMainWindow(){
    setMinimumHeight(500);
    setMinimumWidth(500);
    QSplitter* splitter = new QSplitter();
    _paintingZone1 = new drawwidget();
    _paintingZone2 = new drawwidget();
    _paintingZone3 = new drawwidget();

    _paintingZone2->setStyleSheet("background-color:pink;");
    _paintingZone3->setStyleSheet("background-color:yellow;");

    QWidget* tmp = new QWidget();

    QGridLayout* grid = new QGridLayout();
    grid->setSpacing(0);
    grid->setMargin(0);

    grid->addWidget(_paintingZone1, 0,0,1,1);
    grid->addWidget(_paintingZone2, 0,1,1,1);
    grid->addWidget(_paintingZone3, 1,0,1,2);

    tmp->setLayout(grid);

    splitter->addWidget(tmp);


    setCentralWidget(splitter);
}

