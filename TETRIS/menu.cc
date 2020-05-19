#include "menu.h"

#include <QFont>
#include <QPainter>

menu::menu()
    :patternWidget(){

    //init widget
    _play = new QPushButton("Jouer !");
    _play->setStyleSheet("QPushButton { "
                         "border: 2px solid #8f8f91;"
                         "border-radius: 6px;"
                         "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #f6f7fa, stop: 1 #dadbde); "
                         "min-width: 200px;"
                         "min-height: 80px; }");
    _play->setFont(getFont());

    _leave = new QPushButton("Quitter");
    _leave->setStyleSheet("QPushButton { "
                         "border: 2px solid #8f8f91;"
                         "border-radius: 6px;"
                         "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #f6f7fa, stop: 1 #dadbde); "
                         "min-width: 200px;"
                         "min-height: 80px; }");
    _leave->setFont(getFont());

    _helper = new QPushButton("aide touches");
    _helper->setStyleSheet("QPushButton { "
                         "border: 2px solid #8f8f91;"
                         "border-radius: 6px;"
                         "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #f6f7fa, stop: 1 #dadbde); "
                         "min-width: 200px;"
                         "min-height: 80px; }");
    _helper->setFont(getFont());

    _verticalLayout = new QVBoxLayout();
    _verticalLayout->addWidget(_play);
    _verticalLayout->addWidget(_helper);
    _verticalLayout->addWidget(_leave);


    setLayout(_verticalLayout);
    _verticalLayout->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);

    QObject::connect(_leave, &QPushButton::clicked, this, &patternWidget::close);
}

void menu::hideMenu(){
    setVisible(false);
    setEnabled(false);
}

void menu::showMenu(){
    setVisible(true);
    setEnabled(true);
}

void menu::paintEvent(QPaintEvent *s){
    patternWidget::paintEvent(s);
    QPainter painter(this);
    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(QColor("#036bab"),10));
    //layer inter
    painter.drawRect(50,50,getWidth()-100,getheight()-100);
}
