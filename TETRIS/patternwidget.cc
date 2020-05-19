#include "patternwidget.h"

#include <QPainter>
#include <iostream>

patternWidget::patternWidget()
    :QWidget(), _width(850), _height(900), _font("Times", 20){
    //init window
    setFixedSize(_width,_height);
    setWindowFlags(Qt::CustomizeWindowHint);
    setWindowFlags(Qt::WindowTitleHint);
    setWindowFlags(Qt::WindowSystemMenuHint);
    setWindowFlags(Qt::WindowMinimizeButtonHint);
    setStyleSheet("background-color: #edfbff;");
    randomizeQColorVector();

    _font.setWeight(QFont::DemiBold);
    _font.setCapitalization(QFont::Capitalize);
}

void patternWidget::randomizeQColorVector(){
    _colors.clear();
    //pas tres efficace
    int r,g,b;
    for(size_t i = 0; i < 25; i++){
        r = _rand.bounded(0,255);
        g = _rand.bounded(0,255);
        b = _rand.bounded(0,255);
        _colors.push_back(QColor(r,g,b));
    }
    //std::cout << "randomiser\n";
}

void patternWidget::paintEvent(QPaintEvent *){
//cases de couleur autour du tetris
    QPainter painter(this);
    painter.setPen(QPen(QColor(Qt::white),2));
    for(int i = 0; i < 23;i++){
        painter.setBrush(QColor(_colors.at(i)));
        painter.drawRect(50*i,0,50,50);
        painter.drawRect(50*i,850,50,50);
        painter.drawRect(0,50*i,50,50);
        painter.drawRect(800,50*i,50,50);
    }
    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(QColor("#036bab"),10));
    //layer exter
    painter.drawRect(2,2,getWidth()-4,getheight()-4);
}
