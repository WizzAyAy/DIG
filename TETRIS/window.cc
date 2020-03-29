#include "window.hh"
#include <iostream>

window::window()
    :QWidget(), e(), _width(850), _height(900){
    //init window
    setFixedSize(_width,_height);
    setWindowFlags(Qt::CustomizeWindowHint);
    setWindowFlags(Qt::WindowTitleHint);
    setWindowFlags(Qt::WindowSystemMenuHint);
    setWindowFlags(Qt::WindowMinimizeButtonHint);
    setStyleSheet("background-color: black;");

    e.addBlock(0,0);
    e.addBlock(19,9);
    e.show();

    //boucle infini
    QObject::connect(myTimer, &QTimer::timeout, this, &window::myUpdate);
    myTimer->start(0);
}

void window::paintEvent(QPaintEvent *){
    //dessine la grille du tetris en lui meme
    QPainter painter(this);

    //les blocks
    painter.setPen(QPen(Qt::red,1));
    painter.setBrush(Qt::red);
    int cmpCol = 0;
    int cmpLig = 0;
    for(auto vec : e.getMatrix()){
        for(auto x : vec){
            if(x)
                painter.drawRect(50+40*cmpCol,50+40*cmpLig,40,40);
            cmpCol++;
        }
        cmpCol = 0;
        cmpLig++;
    }

    //grille
    painter.setPen(QPen(Qt::white,3));
    for(size_t i = 0; i < e.getNbCol()-1; i++){
        painter.drawLine(90+i*40, 50, 90+i*40, 850);
    }
    for(size_t i = 0; i < e.getNbLig()-1; i++){
        painter.drawLine(50, 90+i*40, 450, 90+i*40);
    }


    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(Qt::blue,10));
    //layer exter
    painter.drawRect(2,2,_width-4,_height-4);
    //zone tetris
    painter.drawRect(50,50,400,800);
    //zone score
    painter.drawRect(470,50,330,250);
    //zone tetriminos
    painter.drawRect(470,320,330,530);

    std::cout << "update\n";

}

void window::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Escape) close();
}

void window::myUpdate(){
    update();
}
