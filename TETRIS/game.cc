#include <iostream>

#include "game.h"


/*-------------------CONTRUCTEUR && INIT-------------------*/
game::game()
    :patternWidget(), e(){

    //init variables
    _score = 0;
    _speed = 1000;
    _lvl = 1;
    _pause = true;

    //init widget
    _textScore = new QLabel("Score",this);
    _textScore->setStyleSheet("QLabel { background-color : red; color : blue; }");

    _LCDScore = new QLCDNumber(this);
    _LCDScore->display(_score);

    _textScore->setGeometry(500,100,100,50);
    _LCDScore->setGeometry(500,150,100,50);

    //boucle infini
    _myTimer = new QTimer();
    _myTimer->start(_speed);

    //connect
    QObject::connect(_myTimer, &QTimer::timeout, this, &game::myUpdate);
    QObject::connect(&e, &engine::tetriminoChanged, this, &game::updatePaint);
    QObject::connect(&e, &engine::endOfGame, this, &game::goMenu);
}

void game::restartGame(){
    _score = 0;
    _speed = 1000;
    _lvl = 1;
    _textScore->setText("SOCRE");
    _LCDScore->display(_score);
    e.restartEngine();
    _pause = false;
    setEnabled(true);
    show();
}

void game::hideGame(){
    setVisible(false);
    setEnabled(false);
}

/*-------------------LE GRAPHIQUE-------------------*/
void game::paintEvent(QPaintEvent *){
    //dessine la grille du tetris en lui meme
    QPainter painter(this);

    //les tetrimino de la matrix
    painter.setPen(QPen(Qt::red,1));
    painter.setBrush(Qt::red);
    int cmpCol = 0;
    int cmpLig = 0;
    for(auto vec : e.getMatrix()){
        for(auto x : vec){
            if(x.boolean){
                painter.setBrush(x.color);
                painter.drawRect(50+40*cmpCol,50+40*cmpLig,40,40);
            }
            cmpCol++;
        }
        cmpCol = 0;
        cmpLig++;
    }

    //grille jeux
    painter.setPen(QPen(Qt::white,3));
    for(int i = 0; i < e.getNbCol()-1; i++){
        painter.drawLine(90+i*40, 50, 90+i*40, 850);
    }
//    for(int i = 0; i < e.getNbLig()-1; i++){
//        painter.drawLine(50, 90+i*40, 450, 90+i*40);
//    }


    //tetriminos suivant
    int tmp = 0;
    for(auto x : e.getNextTetriminos()){
        for(auto pos : x->getLesPos()){
            painter.setBrush(x->getColor());
            if(tmp == 0)painter.drawRect(530+(pos.col-4)*20,570+pos.ligne*20,20,20);
            if(tmp == 1)painter.drawRect(710+(pos.col-4)*20,570+pos.ligne*20,20,20);
            if(tmp == 2)painter.drawRect(530+(pos.col-4)*20,730+pos.ligne*20,20,20);
            if(tmp == 3)painter.drawRect(710+(pos.col-4)*20,730+pos.ligne*20,20,20);
        }
        tmp++;
    }



    //    //grille next
    //    painter.setPen(QPen(Qt::white,3));
    //    for(int i = 0; i < 7; i++){
    //       painter.drawLine(510+i*40, 530, 510+i*40, 850);

    //    }
    //    for(int i = 0; i < 7; i++){
    //       painter.drawLine(470, 570+i*40, 800, 570+i*40);
    //    }

    painter.setPen(QPen(Qt::blue,5));
    painter.drawLine(470, 570+3*40, 800, 570+3*40);
    painter.drawLine(510+3*40, 530, 510+3*40, 850);

    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(Qt::blue,10));
    //layer exter
    painter.drawRect(2,2,getWidth()-4,getheight()-4);
    //zone tetris
    painter.drawRect(50,50,400,800);
    //zone score
    painter.drawRect(470,50,330,250);
    //zone nextTetriminos
    painter.drawRect(470,530,330,320);
}



/*-------------------LES TOUCHES-------------------*/
void game::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Escape) close();
    if(event->key() == Qt::Key_E) {e.rotateLeftTetrimino();update();}
    if(event->key() == Qt::Key_A) {e.rotateRightTetrimino();update();}
    if(event->key() == Qt::Key_Q) {e.TransLeftTetrimino();update();}
    if(event->key() == Qt::Key_D) {e.TransRightTetrimino();update();}
    if(event->key() == Qt::Key_S) {e.teleportDown();update();}
}

void game::goMenu(){
    emit goBackMenu();
    _pause = true;
}

/*-------------------SLOTS-------------------*/
void game::myUpdate(){
    if(!_pause){
        update();
        e.updateMatrix();
    }
}

void game::updatePaint(){
    update();
}
