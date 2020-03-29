#pragma once

#include <engine.hh>
#include <QtWidgets>

class window : public QWidget
{
        Q_OBJECT

public:
    /*-------------------CONTRUCTEUR && INIT-------------------*/
    window();
    /*-------------------LE GRAPHIQUE-------------------*/
    void paintEvent(QPaintEvent *);
    /*-------------------LES TOUCHES-------------------*/
    void keyPressEvent(QKeyEvent *event);

private:
    engine e;
    int _width;
    int _height;
    QTimer* myTimer;

    /*-------------------SLOTS-------------------*/
public slots:
    void myUpdate();
};
