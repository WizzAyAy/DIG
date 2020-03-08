#pragma once

#include <QtWidgets>
#include <chrono>

#include "mode.hh"

class mainwindow :public QWidget
{
    Q_OBJECT
public:
    mainwindow();
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

signals:
    void goBackMenu(mode a);
    void pb(int time);
private:
    int _width;
    int _height;
};
