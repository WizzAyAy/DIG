#pragma once
#include <QMainWindow>

#include "drawwidget.hh"

class mainwindow : public QMainWindow
{
public:
    mainwindow();

private:
    drawwidget* _paintingZone1;
    drawwidget* _paintingZone2;
    drawwidget* _paintingZone3;
};
