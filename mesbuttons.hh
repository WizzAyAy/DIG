#pragma once

#include <QtWidgets>


class mesButtons : public QPushButton
{
    Q_OBJECT
public:
    mesButtons()=default;
    mesButtons(QString s, QWidget * parent);
    void mouseReleaseEvent(QMouseEvent *even);
signals:
    void jeTeClique(QString);
};
