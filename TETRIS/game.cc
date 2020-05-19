#include <iostream>
#include <QRandomGenerator>

#include "game.h"


/*-------------------CONTRUCTEUR && INIT-------------------*/
game::game()
    :patternWidget(), e(){

    //init variables
    _score = 0;
    _speed = 1000;
    _coin = 0;
    _speedUp = false;
    _lvl = 1;
    _pause = true;

    //init widget
    QFont font("Times", 15, QFont::Bold);

    //score
    _textScore = new QLabel(this);
    _textScore->setStyleSheet("QLabel {color : #000000; }");
    _textScore->setFont(font);

    _LCDScore = new QLCDNumber(this);
    _LCDScore->setDigitCount(7);

    _textScore->setGeometry(500,60,100,50);
    _LCDScore->setGeometry(650,60,100,50);

    //lvl
    _textLvl = new QLabel(this);
    _textLvl->setStyleSheet("QLabel {color : #000000; }");
    _textLvl->setFont(font);

    _LCDLvl = new QLCDNumber(3,this);

    _textLvl->setGeometry(500,120,100,50);
    _LCDLvl->setGeometry(650,120,100,50);

    //coin
    _textCoin = new QLabel(this);
    _textCoin->setStyleSheet("QLabel {color : #000000; }");
    _textCoin->setFont(font);

    _LCDCoin = new QLCDNumber(this);

    _textCoin->setGeometry(500,180,100,50);
    _LCDCoin->setGeometry(650,180,100,50);

    //Speed
    _textSpeed = new QLabel(this);
    _textSpeed->setStyleSheet("QLabel {color : #000000; }");
    _textSpeed->setFont(font);

    _LCDSpeed = new QLCDNumber(this);

    _textSpeed->setGeometry(500,240,100,50);
    _LCDSpeed->setGeometry(650,240,100,50);

    //boucle infini
    _myTimer = new QTimer();

    //connect
    QObject::connect(_myTimer, &QTimer::timeout, this, &game::myUpdate);
    QObject::connect(&e, &engine::tetriminoChanged, this, &game::updatePaint);
    QObject::connect(&e, &engine::endOfGame, this, &game::goEndScreen);
    QObject::connect(&e, &engine::endOfGame, this, &game::endOfGame);
    QObject::connect(&e, &engine::nbLineErase, this, &game::updateScore);
    for(auto x : _power.getlesPowerUp()){
        QObject::connect(x, &powerButton::powerEmit, this, &game::comeBackFromShop);
        QObject::connect(x, &powerButton::powerEmit, this, &game::execPower);
    }
    QObject::connect(&e, &engine::sound, this, &game::soundFromEngine);
}

void game::restartGame(){
    emit sound("gameStart");
    _score = 0;
    _speed = 1000;
    _coin = 0;
    _lvl = 1;
    _myTimer->start(_speed);
    updateWidget();
    e.restartEngine();
    _pause = false;
    setEnabled(true);
    show();
}

void game::hideGame(){
    setVisible(false);
    setEnabled(false);
}

void game::showGame(){
    setVisible(true);
    setEnabled(true);
}

/*-------------------LE GRAPHIQUE-------------------*/
void game::paintEvent(QPaintEvent *p){
    patternWidget::paintEvent(p);
    //dessine la grille du tetris en lui meme
    QPainter painter(this);

    //hallo la ou va tomber lma piece
    int min = 9;
    int max = 0;
    for(auto x : e.getCurrentTetrimino()->getLesPos()){
        if(x.col < min) min = x.col;
        if(x.col > max) max = x.col;
    }
    painter.setPen(QPen(Qt::white,1));
    painter.setBrush(QColor("#ebf1f2"));
    for(int i = min-1; i < max+1; i++){
        painter.drawRect(50+40*min,50,40*(max-min+1),800);
    }

    //les tetrimino de la matrix
    painter.setPen(QPen(Qt::white,1));
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


    //tetriminos suivant
    int tmp = 0;
    for(auto x : e.getNextTetriminos()){
        for(auto pos : x->getLesPos()){
            painter.setBrush(x->getColor());
            if(tmp == 0)painter.drawRect(530+(pos.col-4)*20,580+pos.ligne*20,20,20);
            if(tmp == 1)painter.drawRect(710+(pos.col-4)*20,580+pos.ligne*20,20,20);
            if(tmp == 2)painter.drawRect(530+(pos.col-4)*20,740+pos.ligne*20,20,20);
            if(tmp == 3)painter.drawRect(710+(pos.col-4)*20,740+pos.ligne*20,20,20);
        }
        tmp++;
    }

    //tetrimino qui est dans le handler
    if(e.getHoldingTetrimino() != nullptr){
        painter.setBrush(e.getHoldingTetrimino()->getColor());
        for(auto pos : e.getHoldingTetrimino()->getLesPos()){
            painter.drawRect(615+(pos.col-4)*30,380+pos.ligne*30,30,30);
        }
    }


    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(QColor("#036bab"),10));
    //zone tetris
    painter.drawRect(50,50,400,800);
    //zone score
    painter.drawRect(470,50,330,250);
    //zone handler
    painter.drawRect(470,350,330,130);
    //zone nextTetriminos
    painter.drawRect(470,530,330,320);
    painter.setPen(QPen(QColor("#036bab"),5));
    painter.drawLine(470, 570+3*40, 800, 570+3*40);
    painter.drawLine(510+3*40, 530, 510+3*40, 850);
}





/*-------------------LES TOUCHES-------------------*/
void game::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Escape) close();
    if(event->key() == _key.at(0)) {e.TransLeftTetrimino();update();}
    if(event->key() == _key.at(1)) {e.TransRightTetrimino();update();}
    if(event->key() == _key.at(2)) {e.rotateLeftTetrimino();update();}
    if(event->key() == _key.at(3)) {e.rotateRightTetrimino();update();}
    if(event->key() == _key.at(4)) {e.updateMatrix();update();}
    if(event->key() == _key.at(5)) {e.teleportDown();update();emit sound("hardDrop");}
    if(event->key() == _key.at(6)) {e.holdCurrentTetrimino();}
    if(event->key() == _key.at(7)) {goShop();}
    if(event->key() == _key.at(8)) {emit nextMusic();}
}

void game::goMenu(){
    emit goBackMenu();
    _pause = true;
}

void game::goEndScreen(){
    emit endScreen();
    _pause = true;
}

void game::updateWidget(){
    _textScore->setText("Score");
    _LCDScore->display(_score);

    _textLvl->setText("Lvl");
    _LCDLvl->display(_lvl);

    _textCoin->setText("Coins");
    _LCDCoin->display(_coin);

    _textSpeed->setText("Speed");
    _LCDSpeed->display(-_speed+1500);

}

void game::goShop(){
    hideGame();
    _pause = true;
    _power.showPower();
}

void game::comeBackFromShop(){
    _power.hidePower();
    _pause = false;
    showGame();
}

/*-------------------SLOTS-------------------*/
void game::myUpdate(){
    if(!_pause){
        update();
        e.updateMatrix();
    }
    //std::cout << "update toutes les " << _speed << "ms" << std::endl;
}

void game::updatePaint(){
    update();
}

void game::updateScore(const int &nb){
    if(nb == 4){
        _score += 100 * _lvl * _lvl;
        sound("tetris");
        _coin += 10;
    }
    if(nb == 1){
        _coin += 1;
        sound("1line");
        _score += nb * 1 * _lvl * _lvl;
    }
    if(nb == 2){
        _coin += 3;
        sound("2line");
        _score += nb * 3 * _lvl * _lvl;
    }
    if(nb == 3){
        _coin += 6;
        sound("3line");
        _score += nb * 6 * _lvl * _lvl;
    }

    updateWidget();

}

void game::execPower(int cost, std::string effect){
    if(effect == "back") return;
    if(_coin >= cost){
        if(effect == "eraseLine"){
            e.powerEraseLine();
            _coin -= cost;
            emit sound("coin");
        }

        if(effect == "nextLvl"){
            if(_speed > 100){
                emit sound("levelUp");
                _lvl++;
                setSpeed(_speed-100);
                _coin -= cost;
                emit sound("coin");
            }
            else emit sound("wrong");
        }


        if(effect == "slowSpeed"){
            if (_speed < 1400){
                _coin -= cost;
                emit sound("coin");
                setSpeed(_speed+50);
            }
            else emit sound("wrong");
        }


        if(effect == "tetriminoBombe"){
            e.currentBecomeBomb();
            _coin -= cost;
            emit sound("coin");
        }
        updateWidget();
    }
    else{
        emit sound("noMoney");
    }
}

void game::endOfGame(){
    emit GameOver();
}

void game::setKey(std::vector<Qt::Key> k){
    _key = k;
}

void game::soundFromEngine(std::string name){
    emit sound(name);
}
