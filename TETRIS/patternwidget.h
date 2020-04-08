#pragma once

#include <QWidget>

class patternWidget : public QWidget
{
public:
    patternWidget();
    int getWidth(){return _width;}
    int getheight(){return _height;}
private:
    int _width;
    int _height;
};

