#pragma once
#include <QtWidgets>
#include <vector>

//#include "zonedessin.hh"

struct point
{
    QPoint p;
    QColor c;
};

class drawwidget : public QWidget
{
public:
    drawwidget();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void setBleu(){_color = Qt::blue; _bleu->setDisabled(true); _rouge->setEnabled(true);}
    void setRouge(){_color = Qt::red; _rouge->setDisabled(true); _bleu->setEnabled(true);}

    bool clamp(int mawW, int mawH, int x, int y);

    void reset();
private:
    std::vector<point> _vect;

    QPoint _p;
    QColor _color;

    QPushButton* _effacer;
    QPushButton* _bleu;
    QPushButton* _rouge;

    QHBoxLayout* _layout;
};
