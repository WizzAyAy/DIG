#include "helper.h"

#include <iostream>
#include <QPainter>

helper::helper()
    :patternWidget(), _fileName("./res/save/key.txt"), _file(_fileName), _flux(&_file), _allKeyValid(true){

    _flux.setCodec("UTF-8");    

    _vectorKey.push_back({new QLabel("translation gauche"), new QLineEdit("Q")});
    _vectorKey.push_back({new QLabel("translation droite"), new QLineEdit("D")});
    _vectorKey.push_back({new QLabel("rotation gauche"), new QLineEdit("A")});
    _vectorKey.push_back({new QLabel("rotation droite"), new QLineEdit("E")});
    _vectorKey.push_back({new QLabel("soft drop"), new QLineEdit("S")});
    _vectorKey.push_back({new QLabel("hard drop"), new QLineEdit("Z")});
    _vectorKey.push_back({new QLabel("garder la piece"), new QLineEdit("W")});
    _vectorKey.push_back({new QLabel("ouvrir le shop"), new QLineEdit("C")});
    _vectorKey.push_back({new QLabel("passer la musique"), new QLineEdit("N")});

    _layout = new QVBoxLayout();
    for(auto x : _vectorKey){
        x.label->setStyleSheet("QLabel {color : #000000; }");
        x.label->setFont(getFont());
        x.key->setStyleSheet("QLineEdit {color : #000000; }");
        x.key->setFont(getFont());
        x.key->setMaxLength(1);


        QHBoxLayout* tmp = new QHBoxLayout();
        tmp->addWidget(x.label, Qt::AlignCenter);
        tmp->addWidget(x.key);
        _layout->addLayout(tmp);

        QObject::connect(x.key, &QLineEdit::textChanged, this, &helper::validKey);
    }


    _saveKey = new QPushButton("sauvegarder");
    _saveKey->setStyleSheet("QPushButton { "
                         "border: 2px solid #8f8f91;"
                         "border-radius: 6px;"
                         "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #f6f7fa, stop: 1 #dadbde); "
                         "min-width: 200px;"
                         "min-height: 80px; }");
    _saveKey->setFont(getFont());

    _defaultKey = new QPushButton("remise a zero des touches");
    _defaultKey->setStyleSheet("QPushButton { "
                         "border: 2px solid #8f8f91;"
                         "border-radius: 6px;"
                         "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #f6f7fa, stop: 1 #dadbde); "
                         "min-width: 200px;"
                         "min-height: 80px; }");
    _defaultKey->setFont(getFont());

    _back = new QPushButton("retour");
    _back->setStyleSheet("QPushButton { "
                         "border: 2px solid #8f8f91;"
                         "border-radius: 6px;"
                         "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #f6f7fa, stop: 1 #dadbde); "
                         "min-width: 200px;"
                         "min-height: 80px; }");
    _back->setFont(getFont());

    _layout->addWidget(_saveKey);
    _layout->addWidget(_defaultKey);
    _layout->addWidget(_back);
    _layout->setMargin(70);
    _layout->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);
    setLayout(_layout);

    QObject::connect(_saveKey, &QPushButton::clicked, this, &helper::saveKeyInFile);
    QObject::connect(_defaultKey, &QPushButton::clicked, this, &helper::resetKeyToDefault);
    QObject::connect(_back, &QPushButton::clicked, this, &helper::emitKey);

    //charger les keys depuis le file
    fileKeyToGame();
    updateKey();
    emit newKey(_keyToEmit);
}

void helper::hideHelper(){
    setVisible(false);
    setEnabled(false);
}

void helper::showHelper(){
    setVisible(true);
    setEnabled(true);
    fileKeyToGame();
    updateKey();
}

bool helper::checkAllKey(){
    for(auto it = _vectorKey.begin(); it!= _vectorKey.end(); it++){
        if(it->key->text().toUpper() < "A" || it->key->text().toUpper() > "Z"){
            it->key->setStyleSheet("QLineEdit {color : Red; }");
            return false;
        }
        for(auto itComp = it+1; itComp!= _vectorKey.end(); itComp++){
            if(it->key->text().toUpper() == itComp->key->text().toUpper()){
                it->key->setStyleSheet("QLineEdit {color : Red; }");
                itComp->key->setStyleSheet("QLineEdit {color : Red; }");
                return false;
            }
        }
    }
    for(auto x : _vectorKey){
        x.key->setText(x.key->text().toUpper());
        x.key->setStyleSheet("QLineEdit {color : #000000; }");
    }
    return true;
}

void helper::updateKey(){
    _keyToEmit.clear();
    for(auto x : _vectorKey){
        if(x.key->text() == "A") _keyToEmit.push_back(Qt::Key_A);
        if(x.key->text() == "B") _keyToEmit.push_back(Qt::Key_B);
        if(x.key->text() == "C") _keyToEmit.push_back(Qt::Key_C);
        if(x.key->text() == "D") _keyToEmit.push_back(Qt::Key_D);
        if(x.key->text() == "E") _keyToEmit.push_back(Qt::Key_E);
        if(x.key->text() == "F") _keyToEmit.push_back(Qt::Key_F);
        if(x.key->text() == "G") _keyToEmit.push_back(Qt::Key_G);
        if(x.key->text() == "H") _keyToEmit.push_back(Qt::Key_H);
        if(x.key->text() == "I") _keyToEmit.push_back(Qt::Key_I);
        if(x.key->text() == "J") _keyToEmit.push_back(Qt::Key_J);
        if(x.key->text() == "K") _keyToEmit.push_back(Qt::Key_K);
        if(x.key->text() == "L") _keyToEmit.push_back(Qt::Key_L);
        if(x.key->text() == "M") _keyToEmit.push_back(Qt::Key_M);
        if(x.key->text() == "N") _keyToEmit.push_back(Qt::Key_N);
        if(x.key->text() == "O") _keyToEmit.push_back(Qt::Key_O);
        if(x.key->text() == "P") _keyToEmit.push_back(Qt::Key_P);
        if(x.key->text() == "Q") _keyToEmit.push_back(Qt::Key_Q);
        if(x.key->text() == "R") _keyToEmit.push_back(Qt::Key_R);
        if(x.key->text() == "S") _keyToEmit.push_back(Qt::Key_S);
        if(x.key->text() == "T") _keyToEmit.push_back(Qt::Key_T);
        if(x.key->text() == "U") _keyToEmit.push_back(Qt::Key_U);
        if(x.key->text() == "V") _keyToEmit.push_back(Qt::Key_V);
        if(x.key->text() == "W") _keyToEmit.push_back(Qt::Key_W);
        if(x.key->text() == "X") _keyToEmit.push_back(Qt::Key_X);
        if(x.key->text() == "Y") _keyToEmit.push_back(Qt::Key_Y);
        if(x.key->text() == "Z") _keyToEmit.push_back(Qt::Key_Z);
    }
}

void helper::emitKey(){
    emit newKey(_keyToEmit);
}

void helper::readFile(){
    if(!_file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QString ligne;
    while(! _flux.atEnd())
    {
        ligne = _flux.readLine();
        std::cout << ligne.toStdString() << std::endl;
    }
    _file.close();
}

void helper::saveKeyInFile(){
    emit playSound("bip");
    if(_allKeyValid){
        if(!_file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;
        QString txt("");

        for(auto x : _vectorKey){
            txt += x.key->text() + " \n";
        }
        _flux << txt;
    }
    _file.close();
}

void helper::fileKeyToGame(){
    if(!_file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    for(auto x : _vectorKey) x.key->setText(_flux.readLine());
    _file.close();
}

void helper::resetKeyToDefault(){
    emit playSound("bip");
    if(!_file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    _flux << "Q\n" << "D\n" << "A\n" << "E\n" << "S\n" << "Z\n" << "W\n" << "C\n" << "N\n";
    _file.close();

    fileKeyToGame();
}

void helper::paintEvent(QPaintEvent *s){
    patternWidget::paintEvent(s);
    QPainter painter(this);
    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(QColor("#036bab"),10));
    //layer inter
    painter.drawRect(50,50,getWidth()-100,getheight()-100);
}


void helper::validKey(){
    emit playSound("bip");
    _allKeyValid = checkAllKey();
    if(_allKeyValid){
        emit playSound("ok");
        updateKey();
    }
    else
        emit playSound("not");
}
