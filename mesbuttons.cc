#include "mesbuttons.hh"
#include <iostream>

mesButtons::mesButtons(QString s, QWidget * parent)
    :QPushButton(s,parent){}

void mesButtons::mouseReleaseEvent(QMouseEvent *even)
{
    emit jeTeClique(text());
}
