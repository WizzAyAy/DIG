#include "patternwidget.h"

patternWidget::patternWidget()
    :QWidget(), _width(850), _height(900){
    //init window
    setFixedSize(_width,_height);
    setWindowFlags(Qt::CustomizeWindowHint);
    setWindowFlags(Qt::WindowTitleHint);
    setWindowFlags(Qt::WindowSystemMenuHint);
    setWindowFlags(Qt::WindowMinimizeButtonHint);
    setStyleSheet("background-color: black;");
}
