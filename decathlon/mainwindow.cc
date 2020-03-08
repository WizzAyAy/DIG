#include "mainwindow.hh"
#include <QPainter>


mainwindow::mainwindow()
    :QWidget(){

    _width = 640;
    _height = 480;


    //init window
    setFixedSize(_width,_height);

    setWindowFlags(Qt::CustomizeWindowHint);
    setWindowFlags(Qt::WindowTitleHint);
    setWindowFlags(Qt::WindowSystemMenuHint);
    setWindowFlags(Qt::WindowMinimizeButtonHint);

    setStyleSheet("background-color: #d18b00;");
}

void mainwindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    painter.setPen(QPen(Qt::blue,10));
    painter.drawRect(5,5,_width-10,_height-10);
    painter.setPen(QPen(Qt::white,10));
    painter.drawRect(15,15,_width-30,_height-30);
    painter.setPen(QPen(Qt::red,10));
    painter.drawRect(25,25,_width-50,_height-50);
}

void mainwindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Escape) close();
}

