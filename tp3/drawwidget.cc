#include "drawwidget.hh"
#include <QPointF>
#include <iostream>

//contiendra les composants de l'application et notamment notre composant
//de dessin
drawwidget::drawwidget()
    :QWidget(){

    this->setStyleSheet("background-color:lightblue;");
    _layout = new QHBoxLayout(this);

    _effacer = new QPushButton("effacer", this);
    _effacer->setDisabled(true);

    _color = Qt::blue;
    _bleu = new QPushButton("bleu", this);
    _bleu->setDisabled(true);
    _rouge = new QPushButton("rouge", this);

    _layout->addWidget(_effacer);
    _layout->addWidget(_bleu);
    _layout->addWidget(_rouge);

    _layout->setAlignment(Qt::AlignTop | Qt::AlignRight);
    setLayout(_layout);

    QObject::connect(_effacer, &QPushButton::clicked, this, &drawwidget::reset);
    QObject::connect(_rouge, &QPushButton::clicked, this, &drawwidget::setRouge);
    QObject::connect(_bleu, &QPushButton::clicked, this, &drawwidget::setBleu);
}

void drawwidget::paintEvent(QPaintEvent *event){
    std::cout << "point en " << _p.x() << ", " << _p.y() << std::endl;
    QPainter painter(this);

    for(auto x : _vect){
        if (x.c == Qt::red)
        painter.setPen(QPen(Qt::red,5));
        if (x.c == Qt::blue)
        painter.setPen(QPen(Qt::blue,5));
        painter.drawPoint(x.p);
    }
}

void drawwidget::mousePressEvent(QMouseEvent *event){
    _effacer->setDisabled(false);
    _p = event->pos();
    if(clamp(width(), height(), _p.x(), _p.y())){
        if(_color == Qt::red)
            _vect.push_back({_p,Qt::red});
        if(_color == Qt::blue)
            _vect.push_back({_p,Qt::blue});
    update();
    }
    else std::cout << "point hors borne\n";
}

void drawwidget::mouseMoveEvent(QMouseEvent *event){
    _p = event->pos();
    if(clamp(width(), height(), _p.x(), _p.y())){
        if(_color == Qt::red)
            _vect.push_back({_p,Qt::red});
        if(_color == Qt::blue)
            _vect.push_back({_p,Qt::blue});
    update();
    }
    else std::cout << "point hors borne\n";
}

bool drawwidget::clamp(int mawW, int mawH, int x, int y){
    if(x > 0 && x < mawW){
        if(y > 0 && y < mawH){
            return true;
        }
    }
    return false;
}

void drawwidget::reset(){
    _vect.clear();
    _effacer->setDisabled(true);
    update();
}
