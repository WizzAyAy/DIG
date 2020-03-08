#pragma once

#include "mainwindow.hh"

#include <chrono>

class clique : public mainwindow
{
    Q_OBJECT
public:
    clique();
    void paintEvent(QPaintEvent* event);
    void cliquer();
private:
    int _nbclique;
    QPushButton* _clique;
    QLabel* _labelclique;

    std::chrono::time_point<std::chrono::system_clock> _debut;
    std::chrono::time_point<std::chrono::system_clock> _fin;

    QHBoxLayout* _layclique;
};

