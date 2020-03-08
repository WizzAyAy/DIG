#include "target.hh"

#include <cstdlib>
#include <ctime>
#include <iostream>

target::target(int nb, QWidget *p)
    :QPushButton(QString::fromStdString(std::to_string(nb)), p), _nb(nb){
    setMaximumSize(30,30);
}

void target::mousePressEvent(QMouseEvent *event){
    if(_nb == 15) emit last();
    else emit next();
    setVisible(false);
}
