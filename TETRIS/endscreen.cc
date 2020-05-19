#include "endscreen.h"

#include <iostream>
#include <QPainter>

endScreen::endScreen()
    :patternWidget(){

    _label = new QLabel("Entrez votre nom !");
    _label->setFont(getFont());

    _lineEdit = new QLineEdit("");
    _lineEdit->setFont(getFont());


    _button = new QPushButton("OK");
    _button->setStyleSheet("QPushButton { "
                         "border: 2px solid #8f8f91;"
                         "border-radius: 6px;"
                         "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #f6f7fa, stop: 1 #dadbde); "
                         "min-width: 200px;"
                         "min-height: 80px; }");
    _button->setFont(getFont());

    _labelWorldRecord1 = new QLabel("World Record :");
    _labelWorldRecord1->setFont(getFont());

    _labelWorldRecord2 = new QLabel("je sui la");
    _labelWorldRecord2->setFont(getFont());

    _layout = new QVBoxLayout;
    _layout->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
    _layout->setMargin(150);

    _layout->addWidget(_label);
    _layout->addWidget(_lineEdit);
    _layout->addWidget(_button);
    _layout->addWidget(_labelWorldRecord1);
    _layout->addWidget(_labelWorldRecord2);

    setLayout(_layout);
}

void endScreen::hideEndScreen(){
    setVisible(false);
    setEnabled(false);
}

void endScreen::showEndScreen(){
    setVisible(true);
    setEnabled(true);
}

void endScreen::updateWordlRecord(int const & score, std::string const & name, std::string const & date){
    QString line;
    std::string tScore = std::to_string(score);
    line += QString::fromStdString(tScore);
    line += " par ";
    line += QString::fromStdString(name);
    line += " le ";
    line += QString::fromStdString(date);
    _labelWorldRecord2->setText(line);
    //std::cout << "world record mit a jour\n";
}

void endScreen::paintEvent(QPaintEvent *s){
    patternWidget::paintEvent(s);
    QPainter painter(this);
    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(QColor("#036bab"),10));
    //layer inter
    painter.drawRect(50,50,getWidth()-100,getheight()-100);
}


