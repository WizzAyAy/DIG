#include "traducteur.hh"

traducteur::traducteur()
    :QObject(){
    connect(&w, &window::signalButton, this, &traducteur::redirige);
    connect(this, &traducteur::res, &w, &window::slotegal);

    connect(this, &traducteur::pushcal, &w, &window::slotligne);
    connect(this, &traducteur::pushope, &w, &window::slotOpe);
}

void traducteur::redirige(QString s)
{

    std::cout << s.toStdString() << std::endl;
    if(s >= "0" && s <= "9"){
        std::cout << s.toStdString();
        c.addChar(s.toStdString().c_str()[0]);
        emit pushcal(s);
        return;
    }

    if(s == ","){
        c.addChar('.');
        emit pushcal(s);
        return;
    }

    if(s == "="){
        std::cout << c.equal() << std::endl;
        emit res(c.equal());
        return;
    }

    c.pushValue();
    if(s == "+"){
        c.plus();
    }
    if(s == "-"){
        c.minus();
    }
    if(s == "*"){
        c.times();
    }
    if(s == "/"){
        c.divide();
    }
    if(s == "^2"){
        c.square();
    }
    if(s == ")"){
        c.bracketR();
    }
    if(s == "("){
        c.bracketL();
    }

    emit pushope(s);
}
