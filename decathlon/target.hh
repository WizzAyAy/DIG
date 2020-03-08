#pragma once
#include <QtWidgets>

class target : public QPushButton
{
    Q_OBJECT
public:
    target(int nb, QWidget *p);
    void mousePressEvent(QMouseEvent *event);
signals:
    void last();
    void next();
private:
    int _nb;
};
